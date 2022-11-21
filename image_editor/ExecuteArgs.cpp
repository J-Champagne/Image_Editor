#include "Headers/Image_reader.h"
#include "Headers/Image_readerBMP.h"
#include "Headers/ExecuteArgs.h"

#include <string>
#include <iostream>

ExecuteArgs::ExecuteArgs(int* commands, std::string fileName, std::string copyName) {
	this->commands = commands;
	this->img_read = getReaderFromFileName(fileName, copyName);
	execute();
}

ExecuteArgs::~ExecuteArgs() {
	delete(this->img_read);
}

Image_reader* ExecuteArgs::getReaderFromFileName(std::string fileName, std::string copyName) {
	Image_reader* img_read = NULL;
	std::string newCopyName = copyName;
	std::string dot = ".";
	std::string format = "";
	std::string copy = "(copy)";

	std::size_t pos = fileName.rfind(dot);
	if (pos != std::string::npos) {
		format = fileName.substr(pos);
	}

	if (copyName == "") {
		std::string prefix = fileName.substr(0, pos);
		newCopyName = prefix + copy + format;
	}

	if (format == ".bmp") {
		img_read = new Image_readerBMP(fileName, newCopyName);
	} else {
		img_read = new Image_reader(fileName, newCopyName);
	}

	return img_read;
}

void ExecuteArgs::execute() {
    if (this->commands[1] == 1) {
        int status = this->img_read->grayScale();
        if (status == 1) {
            std::cout << "Error, only 24 bit bmp images are supported " 
            "for conversion to grayscale\n";
        } else {
            this->commands[0] = 1;
        }   
    }

    if (this->commands[0] == 1) {
        this->img_read->write();
    }
}
