#include <cstdio>
#include "XMLReader.h"
#include "FileReader.h"
using namespace std;

int main() {
	vaar_file::FileReader* file_reader = new vaar_file::XMLReader;
	printf("%s\n", file_reader->Read("tutor.xml"));
	return 0;
}