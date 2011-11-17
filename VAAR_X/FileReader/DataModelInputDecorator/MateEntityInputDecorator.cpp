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
// �ļ�: /FileReader/DataModelInputDecorater/MateEntityInputDecorater.cpp
//       ����ļ�ʵ����һ���������XML�ļ�����䵽MateEntity�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLString.hpp>

#include "MateEntityInputDecorator.h"

namespace vaar_file {

// �����DOMģ��Ϊ
// <SWMateEntity> 
// 	<MateEntityType>LINE</MateEntityType> 
// 	<Params> 
// 		<double>0.041560815351485869</double> 
// 		<double>-0.0300263723445255</double> 
// 		<double>0.066160318574043225</double> 
// 		<double>-6.9388939039072284E-17</double> 
// 		<double>1</double> 
// 		<double>0</double> 
// 		<double>0</double> 
// 		<double>0</double> 
// 	</Params> 
// 	<ComponentName>Tutor2-1</ComponentName> 
// </SWMateEntity>
void MateEntityInputDecorator::Parse(const char* id, xercesc::DOMElement* element) {
	if (NULL == id || NULL == element)
		return;
	
	xercesc::DOMElement* current_element = NULL;
	mate_entity_ = std::tr1::shared_ptr<vaar_data::MateEntity>(new vaar_data::MateEntity());
	mate_entity_->SetID(id);

	// ����MateEntityType
	vaar_data::MateEntityType type = vaar_data::MateEntityType::PLANE_MATEENTITY;
	element = element->getFirstElementChild();

	if (NULL != element &&
		0 == strcmp("MateEntityType", xercesc::XMLString::transcode(element->getTagName()))) {

		type = GetMateEntityType(xercesc::XMLString::transcode(element->getTextContent()));
	}
	mate_entity_->SetMateEntityType(type);

	// ����Params
	double params[MATEENTITY_PARAMS_LENGTH];
	element = element->getNextElementSibling();

	if (NULL != element &&
		0 == strcmp("Params", xercesc::XMLString::transcode(element->getTagName()))) {

		int i = 0;
		current_element = element->getFirstElementChild();

		do {
			if (current_element == NULL)
				break;

			sscanf_s(
				xercesc::XMLString::transcode(current_element->getTextContent()),
				"%lf",
				&params[i++]
			);
		} while (
			current_element != element->getLastElementChild(),
			current_element = current_element->getNextElementSibling()
		);
	}
	mate_entity_->SetParams(params);

	// ����ComponentName
	element = element->getNextElementSibling();
	if (NULL != element &&
		0 == strcmp("ComponentName", xercesc::XMLString::transcode(element->getTagName()))) {

		mate_entity_->SetComponentName(
			xercesc::XMLString::transcode(element->getTextContent())
		);
	}

	// ͨ��ComponentName��ȡComponent�����ָ��

}

// ��ȡMateEntity�����ָ��
vaar_data::MateEntity* MateEntityInputDecorator::GetMateEntity() {
	return mate_entity_.get();
}

// ����MateEntityType���ַ���ֵ��ȡö�ٶ���
vaar_data::MateEntityType MateEntityInputDecorator::GetMateEntityType(const char* name) {
	if (0 == strcmp(name, "CONE"))
		return vaar_data::MateEntityType::CONE_MATEENTITY;
	if (0 == strcmp(name, "CYLINDER"))
		return vaar_data::MateEntityType::CYLINDER_MATEENTITY;
	if (0 == strcmp(name, "LINE"))
		return vaar_data::MateEntityType::LINE_MATEENTITY;
	if (0 == strcmp(name, "PLANE"))
		return vaar_data::MateEntityType::PLANE_MATEENTITY;
	if (0 == strcmp(name, "POINT"))
		return vaar_data::MateEntityType::POINT_MATEENTITY;

	return vaar_data::MateEntityType::POINT_MATEENTITY;
}

} // namespacae vaar_file