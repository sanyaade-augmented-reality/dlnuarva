#include "XMLReader.h"
#include "FileReader.h"
#include "../VAARDataModel/DataModel.h"

#include <iostream>

int main() {
	vaar_data::DataModel* data_model = new vaar_data::DataModel();
	vaar_file::FileReader* file_reader = new vaar_file::XMLReader;
	
	file_reader->Read("tutor.xml", *data_model);

	if (NULL != data_model)
		delete data_model;
	if (NULL != file_reader)
		delete file_reader;
	

	return 0;
}