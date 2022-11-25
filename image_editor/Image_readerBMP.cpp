#include "Headers/Image_reader.h"
#include "Headers/Image_readerBMP.h"

#include <string>

Image_readerBMP::Image_readerBMP(std::string fileName, std::string copyName): Image_reader(fileName, copyName) {
        this->width = getIntFromData(this->getOffsetWidth());
        this->length = getIntFromData(this->getOffsetLength());
        this->offsetPixel = getIntFromData(this->getOffsetData());
        this->bpp = getIntFromData(this->getOffsetBpp());
}

Image_readerBMP::~Image_readerBMP() {}

int Image_readerBMP::getOffsetSize() const {return this->offsetSize;}

int Image_readerBMP::getOffsetWidth() const {return this->offsetWidth;}

int Image_readerBMP::getOffsetLength() const {return this->offsetLength;}

int Image_readerBMP::getOffsetData() const {return this->offsetData;}

int Image_readerBMP::getOffsetBpp() const {return this->offsetBpp;}

int Image_readerBMP::getOffsetPixel() const {return this->offsetPixel;}

int Image_readerBMP::getBpp() const {return this->bpp;}

int Image_readerBMP::grayScale() {
    if (this->bpp != 24) {return 1;}
    
    int grey;
    unsigned char blue, green, red;
    unsigned char* image = (unsigned char*) &this->getData()[this->getOffsetPixel()];
    for (int i = 0; i < this->getSize() - this->getOffsetPixel(); i += 3) {
        blue = image[i];
        green = image[i+1];
        red = image[i+2];

        grey = (blue + green + red) / 3;
        image[i] = image[i+1] = image[i+2] = grey;
      }

    return 0; 
}

int Image_readerBMP::brightness(int bright) {
    if (this->bpp != 24) {return 1;} 
    unsigned char* image = (unsigned char*) &this->getData()[this->getOffsetPixel()];
    int color = 0;
    
    for (int i = 0; i < this->getSize() - this->getOffsetPixel(); i++) {
        color = image[i] + bright;
        if (color > 255) {color = 255;}
        else if (color < 0) {color = 0;}
        
        image[i] = color;
    }

    return 0;
}




