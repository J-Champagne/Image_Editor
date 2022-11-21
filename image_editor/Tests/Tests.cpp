#include "../Headers/Image_reader.h"
#include "../Headers/Image_readerBMP.h"

#include <iostream>
#include <string>

int main (int argc, char* argv[]) {
        //Image_readerBMP test
        std::string fn = argv[1];
        Image_readerBMP* img_readBMP = new Image_readerBMP(fn, "copy.bmp");
        std::cout << img_readBMP->getFileName() << std::endl;
        std::cout << img_readBMP->getSize() << std::endl;
	    std::cout << "Width: " << img_readBMP->getWidth() << std::endl;
        std::cout << "Length: " << img_readBMP->getLength() << std::endl;
        return 0;
}


