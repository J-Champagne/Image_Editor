#ifndef EXECUTEARGS_H
#define EXECUTEARGS_H

#include "Image_reader.h"
#include "Image_readerBMP.h"

#include <string>

class ExecuteArgs {
	public:
        ExecuteArgs(int*, std::string, std::string);
        ~ExecuteArgs();	

        void execute();

	private:
        Image_reader* getReaderFromFileName(std::string, std::string);
	        
        int* commands;
        Image_reader* img_read;	
};

#endif
