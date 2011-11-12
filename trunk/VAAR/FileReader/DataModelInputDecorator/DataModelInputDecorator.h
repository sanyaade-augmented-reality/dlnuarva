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
// �ļ�: /FileReader/DataModelInputDecorater/DataModelInputDecorater.h
//       ����ļ�������һ���������XML�ļ�����䵽DataModel�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_DATAMODELINPUTDECORATOR_DATAMODELINPUTDECORATOR_H_
#define FILEREADER_DATAMODELINPUTDECORATOR_DATAMODELINPUTDECORATOR_H_

#include <memory>

#include "InputDecorator.h"
#include "../VAARDataModel/DataModel.h"

namespace vaar_file {

// �������SWComponent Root�ڵ��XML���ݣ�����䵽DataModel����
class DataModelInputDecorator : public InputDecorator {
public:
	// ���캯������������
	DataModelInputDecorator() {}
	~DataModelInputDecorator() {}

	// ����SWComponent Root�ڵ��XML���ݣ�����䵽DataModel����
	virtual void Parse(const char* id, xercesc::DOMElement* element);
	// ��ȡFace����ָ��
	vaar_data::DataModel* GetDataModel();
private:
	// �������
	std::tr1::shared_ptr<vaar_data::DataModel> data_model_;
}; // class DataModelInputDeocrator

} // namespcae vaar_file
#endif