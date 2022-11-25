#include "Headers/Image_reader.h"

#include <iostream>
#include <fstream>
#include <string>

Image_reader::Image_reader(std::string fileName, std::string copyName) {
	this->fileName = fileName;
	this->copyName = copyName;
	this->file.open(fileName, std::ios::binary);
	if (this->file == NULL) {
		std::cerr << "******Error, cannot open file!******\n";
		exit(1);
	}
	this->read();
	this->file.close();
}

Image_reader::~Image_reader() {
	delete this->data;
}

int Image_reader::getWidth() const {return this->width;}

int Image_reader::getLength() const {return this->length;}

long Image_reader::getSize() const {return this->size;}

char* Image_reader::getData() {
	if (this->data == NULL) {
		std::cerr << "Error, no data, NULL value returned!\n";
	}
	return this->data;
}

std::string Image_reader::getFileName() const {return this->fileName;}

std::string Image_reader::getCopyName() const {return this->copyName;}

void Image_reader::read() {
	char* buff;

	//Get size of file
	this->file.seekg(0, this->file.end);
	this->size = this->file.tellg();
	if (this->size == 0) {
		std::cerr << "Error, file is empty!\n";
		exit(1);
	}

	//Copy data
	buff = new char[this->size];
	this->file.seekg(0, this->file.beg);
	this->file.read(buff, this->size);
	this->data = buff;
}

void Image_reader::write() {
	std::ofstream out(this->getCopyName(), std::ios::binary);
	if (out == NULL) {
        std::cerr << "Error, cannot create file!\n";
        exit(1);
	}
	out.write(this->getData(), this->getSize());
	out.close();
}

int Image_reader::getIntFromData(int offset) {
    int* buff = (int*) &this->getData()[offset];
    return buff[0];
}

int Image_reader::grayScale() {return 1;}

int Image_reader::brightness(int) {return 1;}
