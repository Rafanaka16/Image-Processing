    //
// Created by rafan on 3/30/2019.
//

#ifndef SRC_HEADER_H
#define SRC_HEADER_H

#include <iostream>
#include <vector>
using namespace std;

class Image {
public:
    struct Header {
        char idLength;
        char colorMapType;
        char dataTypeCode;
        short colorMapOrigin;
        short colorMapLength;
        char colorMapDepth;
        short xOrigin;
        short yOrigin;
        short width;
        short height;
        char bitsPerPixel;
        char imageDescriptor;

        Header();
    };
    struct Pixel {
        unsigned char RColor, GColor, BColor;
        Pixel &operator * (Pixel pixel);
        Pixel &operator + (Pixel pixel);
        Pixel &operator - (Pixel pixel);
        bool operator == (Pixel pixel);
        Pixel &operator = (Pixel pixel);
    };
//public:
    vector<Pixel> pixelVector;
    Header header;
    //Pixel pixel;
    Image();


};



#endif //SRC_HEADER_H
