#ifndef IMAGE_READER_H
#define IMAGE_READER_H

#include <fstream>
#include <string>

class Image_reader {
	public:
        Image_reader(std::string, std::string);
        virtual ~Image_reader();
	
        int getWidth() const;
        int getLength() const;
        long getSize() const;
        char* getData();
        std::string getFileName() const;
        std::string getCopyName() const;
	
        void write();
        virtual int grayScale();
        virtual int brightness(int);

	protected:
        int width = -1; 
        int length = -1;
        long size = -1;
        char* data = NULL;
        std::string fileName = "";
        std::string copyName = "";
        std::ifstream file;

        void read();
        int getIntFromData(int);
};

#endif
