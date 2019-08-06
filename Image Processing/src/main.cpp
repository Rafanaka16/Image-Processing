#include <iostream>
#include <fstream>
#include <string>
#include "Image.h"
#include "ImageProcessing.h"

using namespace std;
int main() {
    ImageProcessing processorTest;
    Image Rafa;
    Image Marco;
    Image Gaby;
    Image example;
    Image result;
    Image result2;
///task 1
     Marco = processorTest.ReadImage("input/layer1.tga");
     Rafa = processorTest.ReadImage("input/pattern1.tga");
     example = processorTest.ReadImage("examples/EXAMPLE_part1.tga");
     result = processorTest.Multiply(Marco,Rafa);
    processorTest.WriteImage("output/part_1.tga",result);
    if(processorTest.Compare(example, result)){
        cout<<"Task 1 passed" << endl;
    }else
        cout<<"Task 1 failed" << endl;
    //processorTest.DisplayDifferentPixels(example,result);

///task 2

     Marco = processorTest.ReadImage("input/car.tga");
     Rafa = processorTest.ReadImage("input/layer2.tga");
     example = processorTest.ReadImage("examples/EXAMPLE_part2.tga");
     result = processorTest.Substract(Marco,Rafa);
    processorTest.WriteImage("output/part_2.tga",result);
    if(processorTest.Compare(example, result)){
        cout<<"Task 2 passed" << endl;
    }else
        cout<<"Task 2 failed" << endl;
    //processorTest.DisplayDifferentPixels(example,result);


    ///task 3
    Marco = processorTest.ReadImage("input/layer1.tga");
    Rafa = processorTest.ReadImage("input/pattern2.tga");
    Gaby = processorTest.ReadImage("input/text.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part3.tga");
    result = processorTest.Multiply(Marco,Rafa);
    result2 = processorTest.Screen(Gaby, result);
    processorTest.WriteImage("output/part_3.tga",result2);
    if(processorTest.Compare(example, result2)){
        cout<<"Task 3 passed" << endl;
    }else
        cout<<"Task 3 failed" << endl;
    //processorTest.DisplayDifferentPixels(example,result2);


///task 4

    Marco = processorTest.ReadImage("input/layer2.tga");
    Rafa = processorTest.ReadImage("input/circles.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part4.tga");
    result = processorTest.Multiply(Marco,Rafa);
    Gaby = processorTest.ReadImage("input/pattern2.tga");
    result2 = processorTest.Substract(result, Gaby);
    processorTest.WriteImage("output/part_4.tga",result2);
    if(processorTest.Compare(example, result2)){
        cout<<"Task 4 passed" << endl;
    }else
        cout<<"Task 4 failed" << endl;
    //processorTest.DisplayDifferentPixels(example,result2);


    ///task 5
    Marco = processorTest.ReadImage("input/layer1.tga");
    Rafa = processorTest.ReadImage("input/pattern1.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part5.tga");
    result = processorTest.Overlay(Marco,Rafa);
    processorTest.WriteImage("output/part_5.tga",result);
    if(processorTest.Compare(example, result)){
        cout<<"Task 5 passed" << endl;
    }else
        cout<<"Task 5 failed" << endl;
   // processorTest.DisplayDifferentPixels(example,result);

    ///task 6
    Rafa = processorTest.ReadImage("input/car.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part6.tga");
    for(unsigned int i = 0; i <(Rafa.header.height * Rafa.header.width);i++){
        int green = Rafa.pixelVector[i].GColor;
        green += 200;
        if(green > 255)
            Rafa.pixelVector[i].GColor = 255;
        else
            Rafa.pixelVector[i].GColor = green;
    }
    processorTest.WriteImage("output/part_6.tga",Rafa);
    if(processorTest.Compare(example, Rafa)){
        cout<<"Task 6 passed" << endl;
    }else
        cout<<"Task 6 failed" << endl;
//processorTest.DisplayDifferentPixels(example,Rafa);
//processorTest.PrintPixelDifference(example,Rafa);

    ///task 7
    Rafa = processorTest.ReadImage("input/car.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part7.tga");
    for(unsigned int i = 0; i <(Rafa.header.height * Rafa.header.width);i++){
        int red = Rafa.pixelVector[i].RColor;
        red *= 4;
        if(red > 255)
            Rafa.pixelVector[i].RColor = 255;
        else
            Rafa.pixelVector[i].RColor = red;
        Rafa.pixelVector[i].BColor *=0;
    }
    processorTest.WriteImage("output/part_7.tga",Rafa);
    if(processorTest.Compare(example, Rafa)){
        cout<<"Task 7 passed" << endl;
    }else
        cout<<"Task 7 failed" << endl;
    //processorTest.DisplayDifferentPixels(example,Rafa);
    //processorTest.PrintPixelDifference(example,Rafa);


    ///task 8
    Rafa = processorTest.ReadImage("input/car.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part8_r.tga");
   Image example1 = processorTest.ReadImage("examples/EXAMPLE_part8_g.tga");
    Image example2 = processorTest.ReadImage("examples/EXAMPLE_part8_b.tga");
    for(unsigned int i = 0; i <(Rafa.header.height * Rafa.header.width);i++){
        Rafa.pixelVector[i].BColor = Rafa.pixelVector[i].RColor;
        Rafa.pixelVector[i].GColor = Rafa.pixelVector[i].RColor;
    }
    processorTest.WriteImage("output/part8_R.tga",Rafa);
    Image Part_8_R = processorTest.ReadImage("output/part8_R.tga");

    Rafa = processorTest.ReadImage("input/car.tga");
    for(unsigned int i = 0; i <(Rafa.header.height * Rafa.header.width);i++){
        Rafa.pixelVector[i].RColor = Rafa.pixelVector[i].GColor;
        Rafa.pixelVector[i].BColor = Rafa.pixelVector[i].GColor;
    }
    processorTest.WriteImage("output/part8_G.tga",Rafa);
    Image Part_8_G = processorTest.ReadImage("output/part8_G.tga");

    Rafa = processorTest.ReadImage("input/car.tga");
    for(unsigned int i = 0; i <(Rafa.header.height * Rafa.header.width);i++){
        Rafa.pixelVector[i].RColor = Rafa.pixelVector[i].BColor;
        Rafa.pixelVector[i].GColor = Rafa.pixelVector[i].BColor;
    }
    processorTest.WriteImage("output/part8_B.tga",Rafa);
    Image Part_8_B = processorTest.ReadImage("output/part8_B.tga");
    if((processorTest.Compare(example, Part_8_R))&&(processorTest.Compare(example1,Part_8_G))&&(processorTest.Compare(example2,Part_8_B))){
        cout<<"Task 8 passed" << endl;
    }else
        cout<<"Task 8 failed" << endl;
   // processorTest.DisplayDifferentPixels(example,Part_8_R);
    //processorTest.DisplayDifferentPixels(example,Part_8_G);
    //processorTest.DisplayDifferentPixels(example,Part_8_B);
    //processorTest.PrintPixelDifference(example,Part_8_R);
    //processorTest.PrintPixelDifference(example,Part_8_G);
    //processorTest.PrintPixelDifference(example,Part_8_B);

    ///task 9
     Rafa = processorTest.ReadImage("input/layer_red.tga");
     Marco = processorTest.ReadImage("input/layer_green.tga");
     Gaby = processorTest.ReadImage("input/layer_blue.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part9.tga");
    for(unsigned int i = 0; i <(Rafa.header.height * Rafa.header.width);i++){
        Rafa.pixelVector[i].BColor = 0;
        Rafa.pixelVector[i].GColor = 0;
        Marco.pixelVector[i].RColor = 0;
        Marco.pixelVector[i].BColor = 0;
        Gaby.pixelVector[i].RColor = 0;
        Gaby.pixelVector[i].GColor = 0;
    }
    result = processorTest.Screen(Rafa, Marco);
    result = processorTest.Screen(result, Gaby);
    processorTest.WriteImage("output/part_9.tga",result);
    if(processorTest.Compare(example, result)){
        cout<<"Task 9 passed" << endl;
    }else
        cout<<"Task 9 failed" << endl;
    //processorTest.DisplayDifferentPixels(example,result);
    //processorTest.DisplayDifferentPixels(example,result);

    ///task 10
    Rafa = processorTest.ReadImage("input/text2.tga");
    example = processorTest.ReadImage("examples/EXAMPLE_part10.tga");
    for(unsigned int i=0; i < (Rafa.header.width); i++){
        unsigned int j = i;
        unsigned int k = (Rafa.header.width*Rafa.header.height ) - i -1;
        while(j<k){
            swap(Rafa.pixelVector[j],Rafa.pixelVector[k]);
            j+=Rafa.header.width;
            k-=Rafa.header.width;
        }
    }
processorTest.WriteImage("output/part_10.tga",Rafa);
    if(processorTest.Compare(example, Rafa)){
        cout<<"Task 10 passed" << endl;
    }else
        cout<<"Task 10 failed" << endl;
   // processorTest.DisplayDifferentPixels(example,Rafa);
    //processorTest.DisplayDifferentPixels(example,Rafa);


     return 0;

}
