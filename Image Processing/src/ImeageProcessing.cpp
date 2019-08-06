//
// Created by rafan on 3/30/2019.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "Image.h"
#include "ImageProcessing.h"

using namespace std;

Image ImageProcessing::ReadImage(string fileName) {

    Image image;
    ifstream file(fileName, ios_base::binary);
    if(!file.is_open()){
        cout<<"File is Closed";
    }
    file.read(&image.header.idLength, 1);
    file.read(&image.header.colorMapType, 1);
    file.read(&image.header.dataTypeCode, 1);
    file.read(reinterpret_cast<char *>(&image.header.colorMapOrigin), 2);
    file.read(reinterpret_cast<char *>(&image.header.colorMapLength), 2);
    file.read(&image.header.colorMapDepth, 1);
    file.read(reinterpret_cast<char *>(&image.header.xOrigin), 2);
    file.read(reinterpret_cast<char *>(&image.header.yOrigin), 2);
    file.read(reinterpret_cast<char *>(&image.header.width), 2);
    file.read(reinterpret_cast<char *>(&image.header.height), 2);
    file.read(&image.header.bitsPerPixel, 1);
    file.read(&image.header.imageDescriptor, 1);

    for (unsigned int i = 0; i < (image.header.height * image.header.width); i++) {
        Image::Pixel pixel;
        file.read(reinterpret_cast<char *>(&pixel.BColor), 1);
        file.read(reinterpret_cast<char *>(&pixel.GColor), 1);
        file.read(reinterpret_cast<char *>(&pixel.RColor), 1);
        image.pixelVector.push_back(pixel);
    }
    return image;
}

void ImageProcessing::WriteImage(string fileName, Image image) {
    //Image image;
    ofstream file(fileName, ios_base::out | ios_base::binary);
    file.write(&image.header.idLength, 1);
    file.write(&image.header.colorMapType, 1);
    file.write(&image.header.dataTypeCode, 1);
    file.write(reinterpret_cast<char *>(&image.header.colorMapOrigin), 2);
    file.write(reinterpret_cast<char *>(&image.header.colorMapLength), 2);
    file.write(&image.header.colorMapDepth, 1);
    file.write(reinterpret_cast<char *>(&image.header.xOrigin), 2);
    file.write(reinterpret_cast<char *>(&image.header.yOrigin), 2);
    file.write(reinterpret_cast<char *>(&image.header.width), 2);
    file.write(reinterpret_cast<char *>(&image.header.height), 2);
    file.write(&image.header.bitsPerPixel, 1);
    file.write(&image.header.imageDescriptor, 1);

    for (unsigned int i = 0; i < (image.header.height * image.header.width); i++) {
        Image::Pixel pixel = image.pixelVector[i];
        file.write(reinterpret_cast<char *>(&pixel.BColor), 1);
        file.write(reinterpret_cast<char *>(&pixel.GColor), 1);
        file.write(reinterpret_cast<char *>(&pixel.RColor), 1);
        //image.pixelVector.push_back(pixel);
    }
}


Image ImageProcessing::Substract(Image imageA, Image imageB) {
    Image output;
    output.header = imageA.header;
    for(unsigned int i = 0; i <(imageA.header.height * imageA.header.width); i++ ){
        output.pixelVector.push_back(imageA.pixelVector[i] - imageB.pixelVector[i]);
    }
    return output;
}
Image ImageProcessing::Multiply(Image imageA, Image imageB ) {
    Image output;
    output.header = imageA.header;
    for(unsigned int i = 0; i <(imageA.header.height * imageA.header.width); i++ ){
        output.pixelVector.push_back(imageA.pixelVector[i] * imageB.pixelVector[i]);
    }
    return output;
}

Image ImageProcessing::Screen(Image imageA, Image imageB) {
    Image output;
    output.header = imageA.header;
    Image::Pixel tempPixel1;
    Image::Pixel tempPixel2;
    Image::Pixel tempPixel3;
    for(unsigned int i = 0; i <(imageA.header.height * imageA.header.width); i++ ){
        tempPixel1.RColor = tempPixel2.RColor = tempPixel3.RColor = 255;
        tempPixel1.GColor = tempPixel2.GColor = tempPixel3.GColor = 255;
        tempPixel1.BColor = tempPixel2.BColor = tempPixel3.BColor = 255;

        Image::Pixel resutlA = tempPixel2 - imageA.pixelVector[i];
        Image::Pixel resutlB = tempPixel3 - imageB.pixelVector[i];
        Image::Pixel resultC = resutlA * resutlB;
        Image::Pixel final = tempPixel1 - resultC;
        output.pixelVector.push_back(final);
        //output.pixelVector.push_back(tempPixel1 - ((tempPixel2 - imageA.pixelVector[i]) * (tempPixel3 - imageB.pixelVector[i])));
    }
    return output;
}

Image ImageProcessing::Overlay(Image imageA, Image imageB) {
    Image output;
    output.header = imageA.header;
    for(unsigned int i = 0; i <(imageA.header.height * imageA.header.width); i++ ){
        float red = 0;
        float redOneFactA = imageA.pixelVector[i].RColor / 255.0f;
        float redOneFactB = imageB.pixelVector[i].RColor / 255.0f;
        if(redOneFactB <= 0.5) { red = 2.0f * redOneFactA * redOneFactB; }
        else { red = 1.0f - 2.0f*(1.0f - redOneFactA)*(1.0f - redOneFactB); }
        red = red*255.0f + 0.5f;

        float green = 0;
        float greenOneFactA = imageA.pixelVector[i].GColor / 255.0f;
        float greenOneFactB = imageB.pixelVector[i].GColor / 255.0f;
        if(greenOneFactB <= 0.5) { green = 2.0f * greenOneFactA * greenOneFactB; }
        else { green = 1.0f - 2.0f*(1.0f - greenOneFactA)*(1.0f - greenOneFactB); }
        green = green*255.0f + 0.5f;

        float blue = 0;
        float blueOneFactA = imageA.pixelVector[i].BColor / 255.0f;
        float blueOneFactB = imageB.pixelVector[i].BColor / 255.0f;
        if(blueOneFactB <= 0.5) { blue = 2.0f * blueOneFactA * blueOneFactB; }
        else { blue = 1.0f - 2.0f*(1.0f - blueOneFactA)*(1.0f - blueOneFactB); }
        blue = blue*255.0f + 0.5f;

        Image::Pixel tempPixel;
        tempPixel.RColor = red;
        tempPixel.GColor = green;
        tempPixel.BColor = blue;
        output.pixelVector.push_back(tempPixel);
    }
    return output;
}

bool ImageProcessing::Compare(Image ImageA, Image ImageB) {
    for (unsigned int i = 0; i < (ImageA.header.width * ImageA.header.height); i++) {
        if (!(ImageA.pixelVector[i] == ImageB.pixelVector[i])) {
            return false;
        }
    }
    return true;

}



