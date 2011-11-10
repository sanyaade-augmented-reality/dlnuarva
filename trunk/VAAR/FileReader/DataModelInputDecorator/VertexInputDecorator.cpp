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
// �ļ�: /FileReader/DataModelInputDecorater/VertexInputDecorater.cpp
//       ����ļ�ʵ����һ���������XML�ļ�����䵽Vertrx�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#include <cstring>

#include <xercesc/util/XMLString.hpp>

#include "VertexInputDecorator.h"

namespace vaar_file {


// �����DOMģ��Ϊ
// <SWVertex>
// 	<X>0.049999999999999989</X>
// 	<Y>0.059999999999999984</Y> 
// 	<Z>0</Z> 
// </SWVertex>
void VertexInputDecorator::Parse(const char *id, xercesc::DOMElement* element) {
	if (NULL == element)
		return;

	double x = 0.0, y = 0.0, z = 0.0;
	
	xercesc::DOMElement* current_element = NULL;

	current_element = element->getFirstElementChild();
	do {
		if (NULL != current_element) {
			const char* name = xercesc::XMLString::transcode(current_element->getTagName());

			if (0 == strcmp(name, "X")) 
				sscanf_s(xercesc::XMLString::transcode(current_element->getTextContent()), "%lf", &x);
			if (0 == strcmp(name, "Y")) 
				sscanf_s(xercesc::XMLString::transcode(current_element->getTextContent()), "%lf", &y);
			if (0 == strcmp(name, "Z")) 
				sscanf_s(xercesc::XMLString::transcode(current_element->getTextContent()), "%lf", &z);
		}
	} while (
			 current_element != element->getLastElementChild(),
			 current_element = current_element->getNextElementSibling()
	);

	vertex_ = std::shared_ptr<vaar_data::Vertex>(new vaar_data::Vertex(id, x, y, z));
}

// ��ȡVertex�����ָ��
vaar_data::Vertex* VertexInputDecorator::GetVertex() {
	return vertex_.get();
}

} // namespace vaat_file