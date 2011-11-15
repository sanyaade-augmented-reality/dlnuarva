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
// �ļ�: /FileReader/DataModelInputDecorater/MateEntityInputDecorater.h
//       ����ļ�������һ���������XML�ļ�����䵽MateEntity�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_DATAMODELINPUTDECORATOR_MATEENTITYINPUTDECORATOR_H_
#define FILEREADER_DATAMODELINPUTDECORATOR_MATEENTITYINPUTDECORATOR_H_

#include <memory>

#include "InputDecorator.h"
#include "../../VAARDataModel/MateEntity.h"

namespace vaar_file {

// �������SWMateEntity�ڵ��XML���ݣ�����䵽Entity����
class MateEntityInputDecorator : public InputDecorator {
public:
	// ���캯������������
	MateEntityInputDecorator() {}
	~MateEntityInputDecorator() {}
	// ����SWFace�ڵ��XML���ݣ�����䵽Face����
	virtual void Parse(const char* id, xercesc::DOMElement* element);
	// ��ȡFace����ָ��
	vaar_data::MateEntity* GetMateEntity();
private:
	// ����MateEntityType���ַ���ֵ��ȡö�ٶ���
	vaar_data::MateEntityType GetMateEntityType(const char* name);

	// �������
	std::tr1::shared_ptr<vaar_data::MateEntity> mate_entity_;
}; // class MateEntityInputDecorator

} // namespace vaar_file
#endif