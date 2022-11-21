# Makefile
CLASS_PATH = image_editor/
HEADER_PATH = ${CLASS_PATH}Headers/
TEST_PATH = ${CLASS_PATH}Tests/
EXEC = img_editor.exe
FILES = Image_reader.o Image_readerBMP.o Arguments.o ExecuteArgs.o
OPTIONS = -O3 -Wall -Wextra -Wno-c++11-extensions

# Main
all : img_compressor

img_compressor : main.cpp ${FILES} 
		g++ ${OPTIONS} -o ${EXEC} main.cpp ${FILES}

Image_reader.o : ${CLASS_PATH}Image_reader.cpp ${HEADER_PATH}Image_reader.h
		g++ ${OPTIONS} -c ${CLASS_PATH}Image_reader.cpp

Image_readerBMP.o : ${CLASS_PATH}Image_readerBMP.cpp ${HEADER_PATH}Image_readerBMP.h
		g++ ${OPTIONS} -c ${CLASS_PATH}Image_readerBMP.cpp

Arguments.o : ${CLASS_PATH}Arguments.cpp ${HEADER_PATH}Arguments.h
		g++ ${OPTIONS} -c ${CLASS_PATH}Arguments.cpp

ExecuteArgs.o : ${CLASS_PATH}ExecuteArgs.cpp ${HEADER_PATH}ExecuteArgs.h
		g++ ${OPTIONS} -c ${CLASS_PATH}ExecuteArgs.cpp

# Tests
test_compile: ${TEST_PATH}Tests.cpp ${FILES}
	g++ ${OPTIONS} -o ${TEST_PATH}tests.exe ${TEST_PATH}Tests.cpp ${FILES}

test : test_compile
	${TEST_PATH}tests.exe ${TEST_PATH}bmp_24.bmp	

# Clean
clean :
	rm ${EXEC} ${TEST_PATH}tests.exe *.o
