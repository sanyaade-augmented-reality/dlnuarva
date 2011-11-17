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
// �ļ�: /FileReader/DataModelInputDecorater/VertexInputDecorater.h
//       ����ļ�������һ���������XML�ļ�����䵽Vertrx�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_DATAMODELINPUTDECORATOR_VERTEXINPUTDECORATOR_H_
#define FILEREADER_DATAMODELINPUTDECORATOR_VERTEXINPUTDECORATOR_H_

#include <memory>

#include "../../VAARDataModel/Vertex.h"
#include "InputDecorator.h"

namespace vaar_file {

// �������Vertex�ڵ��XML���ݣ�����䵽Vertex����
class VertexInputDecorator : public InputDecorator {
public:
	// ���캯������������
	VertexInputDecorator(){}
	~VertexInputDecorator(){}

	// ����Vertex�ڵ��XML���ݣ�����䵽Vertex����
	virtual void Parse(const char* id, xercesc::DOMElement* element);
	// ��ȡVertex�����ָ��
	vaar_data::Vertex* GetVertex();
private:
	// �������
	std::tr1::shared_ptr<vaar_data::Vertex> vertex_;
}; // class VertrxInputDecorator

} // namespace vaarfile
#endif