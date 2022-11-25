#include "Headers/Arguments.h"
#include "Headers/ExecuteArgs.h"

#include <iostream>
#include <string_view>
#include <string>
#include <vector>

//Total amount of operations to be applied on an image avaiable (e.g. Huffman compression algorithm)
#define NUM_COMMS 3

//Messages 
const std::string VERSION_MSG = "Version 1.1";
const std::string TOO_MANY_MSG = "Error, too many arguments. (Max 64)";
const std::string TOO_FEW_MSG = "Error, too few arguments. Type --help for usage";
const std::string NO_FILE_MSG = "Error, no file to open. Type --help for usage";
const std::string UNKNOWN_ARG_MSG = "Error, unknown argument. Type --help for usage";
const std::string NO_BRIGHTVAL_MSG = "Error, no value for brightness";
const std::string WRONG_BRIGHTVAL_MSG = "Error, value for brightness needs to be a integral.";
const std::string OVER_BRIGHTVAL_MSG = "Error, value for brightness is too extreme.";
const std::string HELP_MSG = "\nUsage: img_editor.exe     [-h | --help] [-v | --version] [-f | —file <path>]\n"
			     "                          [-o | --output <path>] [-c | --copy] [-g | --grey | --gray]\n"
                 "                          [-b | --brightness <integral>]\n\n"
                 	     "These are common commands used in various situations:\n\n" 
                             "-v —-version       Shows current version.\n"
                             "-f —-file          Indicate image file to use. Must be followed by a path to the desired file.\n" 
			     "-o --output        Indicate name to use for copy of image. Must be followed by a path for the newly created file.\n"
			     "                   By default, '(copy)' is appended between the image name and it's format. Ex. image.bmp -> image(copy).bmp\n" 
			     "-c --copy          Copies the specified image.\n"
                 "-g --grey --gray   Converts image to grayscale. Automatically creates a copy of the image. *Only 24 bit BMP images supported*\n"
                 "-b --brightness    Adjusts the brightness. Must be followed by an integral.\n";

Arguments::Arguments(int argc, char* argv[]) {
	if (argc > 65) {
		printMsg(1);
		exit(1);
	} else if (argc <= 1) {
		printMsg(2);
		exit(2);
	}
	const std::vector<std::string_view> args(argv + 1, argv + argc);	
	this->args = args;
	this->argc = argc -1;
	parseArgs();
}

Arguments::~Arguments() {}

void Arguments::printMsg(int code) {
	std::string msg = "";
	switch (code) {
		case 1:
			msg = TOO_MANY_MSG;
			break;
		case 2:
			msg = TOO_FEW_MSG;
			break;
		case 3:
			msg = NO_FILE_MSG;
			break;
		case 4:
			msg = UNKNOWN_ARG_MSG;
			break;
        case 5:
            msg = NO_BRIGHTVAL_MSG;
            break;
        case 6:
            msg = WRONG_BRIGHTVAL_MSG;
            break;
        case 7:
            msg = OVER_BRIGHTVAL_MSG;
            break;
        case 10:
			msg = HELP_MSG;
			break;
		case 11:
			msg = VERSION_MSG;
			break;
	}
	std::cout << msg << std::endl;
}

void Arguments::parseArgs() {
	int argc = this->argc;
	int commands[NUM_COMMS];
    int brightness = 0;
    std::size_t pos = 0;
	std::vector<std::string_view> args = this->args;
	std::string fileName = "";
	std::string copyName = "";
    std::string temp = "";
    std::string_view arg;

	//Initialise array of commands to 0
	for (int i = 0; i < NUM_COMMS; i++) {
		commands[i] = 0;
	}

	//Parses arguments and sets value of a command to 1 if present in args
	for (int i = 0; i < argc; i++) {
		arg = args[i];	

		if (arg == "-h" || arg == "--help") {
			printMsg(10);
			exit(0);
		
		} else if (arg == "-v" || arg == "--version") {
			printMsg(11);
			exit(0);
		
		} else if (arg == "-f" || arg == "--file")  {
			i++;
			if (i >= argc) {
				printMsg(3);
				exit(3);
			}
			fileName = args[i];
		
		} else if (arg == "-o" || arg == "--output") {
			i++;
            if (i >= argc) {
                printMsg(3);
                exit(3);
            }
            copyName = args[i];

		} else if (arg == "-c" || arg == "--copy") {
			commands[0] = 1;

        } else if (arg == "-g" || arg == "--grey" || arg == "--gray") {
            commands[1] = 1;

        } else if (arg == "-b" || arg == "--brightness") {
            i++;
            if (i >= argc) {
                printMsg(5);
                exit(5);
            }
            
           temp = std::string(args[i]);
           try {
                brightness = std::stoi(temp, &pos);
            } catch (const std::invalid_argument& ia) {
                printMsg(6);
                exit(6);
            } catch (const std::out_of_range& oor) {
                printMsg(7);
                exit(7);
            }
            if (pos != temp.length()) {
                printMsg(6);
                exit(6);
            }
            commands[2] = brightness;
    
		} else {
			printMsg(4);
			exit(4);
		}
	}

	//Execute commands specified in args
	ExecuteArgs* exec = new ExecuteArgs(commands, fileName, copyName);
	delete(exec);
}
