#include <iostream>
#include <fstream>
#include <vector>
#include "Image.h"
using namespace std;

Image::Image() {
    header = Header();
}

Image::Header::Header() {
    width=0;
    height =0;
     idLength = 0;
     colorMapType = 0;
     dataTypeCode = 0;
     colorMapOrigin =0;
     colorMapLength = 0;
     colorMapDepth = 0;
     xOrigin = 0;
     yOrigin = 0;
     bitsPerPixel = 0;
     imageDescriptor = 0;
}

Image::Pixel &Image::Pixel::operator*(Image::Pixel pixel) {
    float tempFloat;
    tempFloat = ((((this->RColor / 255.0f) * (pixel.RColor / 255.0f)) * 255.0f) + 0.5f);
    this->RColor = (unsigned char) tempFloat;
    //this->RColor = ((((this->RColor / 255.0f) * (pixel.RColor / 255.0f)) * 255.0f) + 0.5f);
    tempFloat = (((this->GColor / 255.0f) * (pixel.GColor / 255.0f)) * 255.0f) + 0.5f;
    this->GColor = (unsigned char) tempFloat;
    //this->GColor = (((this->GColor / 255.0f) * (pixel.GColor / 255.0f)) * 255.0f) + 0.5f;
    tempFloat = (((this->BColor / 255.0f) * (pixel.BColor / 255.0f)) * 255.0f) + 0.5f;
    this->BColor = (unsigned char) tempFloat;
    //this->BColor = (((this->BColor / 255.0f) * (pixel.BColor / 255.0f)) * 255.0f) + 0.5f;
    return *this;
}

Image::Pixel &Image::Pixel::operator-(Image::Pixel pixel) {
    int tempInt = RColor;
    tempInt -= pixel.RColor;
    if (tempInt < 0)
        this->RColor = 0;
    else
        this->RColor = tempInt;
    tempInt = GColor;
    tempInt -= pixel.GColor;
    if (tempInt < 0)
        this->GColor = 0;
    else
        this->GColor = tempInt;
    tempInt = BColor;
    tempInt -= pixel.BColor;
    if (tempInt < 0)
        this->BColor = 0;
    else
        this->BColor = tempInt;
    return *this;
}

Image::Pixel &Image::Pixel::operator+(Image::Pixel pixel) {
    int tempInt = RColor;
    tempInt -= pixel.RColor;
    if(tempInt >255)
        this->RColor = 0;
    else
        this->RColor = tempInt;
    tempInt -= pixel.GColor;
    if(tempInt >255)
        this->GColor = 0;
    else
        this->GColor = tempInt;
    tempInt -= pixel.BColor;
    if(tempInt >255)
        this->BColor = 0;
    else
        this->BColor = tempInt;
    return *this;
}

bool Image::Pixel::operator==(Image::Pixel pixel) {
    return pixel.RColor == this->RColor &&
    pixel.BColor == this->BColor &&
    pixel.GColor == this->GColor;
}

Image::Pixel &Image::Pixel::operator=(Image::Pixel pixel) {
    this->RColor = pixel.RColor;
    this->GColor = pixel.GColor;
    this->BColor = pixel.BColor;
    return *this;
}


