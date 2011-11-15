//////////////////////////////////////////////////////////////////////////
// ��Ȩ���� (C) 2011  ��������ѧԺ
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// ����: ����, alex890714@gmail.com
// �ļ�: /FileReader/XMLReader.h
//       ����ļ������˶�ȡXML�ļ����ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_XMLREADER_H_
#define FILEREADER_XMLREADER_H_

#include "FileReader.h"
#include "DataModelInputDecorator/DataModelInputDecorator.h"

namespace vaar_file {

//�����ȡXML�ļ�����
class XMLReader : public FileReader {

public:
	// ���캯������������
	XMLReader() {
		input_ = NULL;
	}
	~XMLReader() {
		if (NULL != input_)
			delete input_;
	}

	// �����ļ�·��������DataModel����
	virtual __declspec(dllexport) void Read(const char* file_path, vaar_data::DataModel& data_model);

private:
	// input
	DataModelInputDecorator* input_;

};

} // namespace vaar_file

#endif