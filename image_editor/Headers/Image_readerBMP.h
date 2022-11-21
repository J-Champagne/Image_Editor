#ifndef BMP_H
#define BMP_H

#include <string>

class Image_readerBMP : public Image_reader {
	public:
        Image_readerBMP(std::string, std::string);
        ~Image_readerBMP();		
		
        int getOffsetSize() const;
        int getOffsetWidth() const;
        int getOffsetLength() const;
        int getOffsetData() const;
        int getOffsetBpp() const;
        int getOffsetPixel() const;
        int getBpp() const;

        void getHeaderInfo();	
        int grayScale();

	private:
        int offsetSize = 2;
        int offsetWidth = 18;
        int offsetLength = 22;
        int offsetData = 10;
        int offsetBpp = 28;
        int offsetPixel = -1; 
        int bpp = -1;
};

#endif
