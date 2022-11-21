#include "image_editor/Headers/Arguments.h"

int main(int argc, char* argv[]) {
	Arguments* args = new Arguments(argc, argv);
	delete(args);
	return 0;
}
