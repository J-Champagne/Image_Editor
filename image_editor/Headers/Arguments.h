#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string_view>
#include <vector>

class Arguments {
	public:
        Arguments(int, char**);
        ~Arguments();
		
        void parseArgs();

	private:
        int argc;
        std::vector<std::string_view> args;
		
        void printMsg(int);		
};

#endif

