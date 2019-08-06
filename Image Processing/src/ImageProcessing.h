//
// Created by rafan on 3/30/2019.
//

#ifndef PROJECT22_IMAGEPROCESSING_H
#define PROJECT22_IMAGEPROCESSING_H

#include <iostream>
#include "Image.h"
#include <fstream>
#include "vector"
using namespace std;

class ImageProcessing {
public:
    Image ReadImage(string fileName);
    void WriteImage(string fileName, Image image);
    Image Multiply(Image imageA, Image imageB);
    Image Substract(Image imageA, Image imageB);
    Image Screen (Image imageA, Image imageB);
    Image Overlay(Image imageA, Image imageB);
    bool Compare(Image ImageA, Image ImageB);


};


#endif //PROJECT22_IMAGEPROCESSING_H
