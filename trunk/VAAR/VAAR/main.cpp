#include "XMLReader.h"
#include "FileReader.h"

#include <iostream>

int main() {
	vaar_file::FileReader* file_reader = new vaar_file::XMLReader;
	std::cout << file_reader->Read("tutor.xml") << std::endl;

	return 0;
}