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
// �ļ�: /FileReader/DataModelInputDecorater/CurveInputDecorater.cpp
//       ����ļ�ʵ����һ���������XML�ļ�����䵽Curve�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#include <xercesc/util/XMLString.hpp>

#include "CurveInputDecorator.h"

namespace vaar_file {

// �����DOMģ��Ϊ
// <Curve> 
// 	    <CurveType>CIRCLE</CurveType> 
// 		<Params> 
// 			<double>-0.05</double>
// 			<double>-0.050000000000000017</double>
// 			<double>0</double>
// 			<double>0</double>
// 			<double>-0</double>
// 			<double>-1</double>
// 			<double>0.01</double>
// 			<double>0</double>
// 			<double>0</double>
// 			<double>0</double>
// 			<double>0</double> 
// 		</Params> 
// </Curve>
void CurveInputDecorator::Parse(const char *id, xercesc::DOMElement* element) {
	if (NULL == element)
		return;

	vaar_data::CurveType type = vaar_data::CurveType::LINE_CURVE;
	double params[CURVE_PARAMS_LENGTH];
	xercesc::DOMElement* current_element = NULL;
	int i = 0;

	// ��������
	element = element->getFirstElementChild();
	if (NULL != element && 
		0 == strcmp("CurveType", xercesc::XMLString::transcode(element->getTagName()))) {
		type = GetCurveType(xercesc::XMLString::transcode(element->getTextContent()));
	}

	// ��������
	element = element->getNextElementSibling();
	if (NULL != element && 
		0 == strcmp("Params", xercesc::XMLString::transcode(element->getTagName()))) {
		
		current_element = element->getFirstElementChild();
		do {
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

	// ������
	curve_ = std::tr1::shared_ptr<vaar_data::Curve>(new vaar_data::Curve(id, type, params));
}

// ��ȡCurve�����ָ��
vaar_data::Curve* CurveInputDecorator::GetCurve() {
	return curve_.get();
}

// ��ȡCurveType
vaar_data::CurveType CurveInputDecorator::GetCurveType(const char* name) {
	if (0 == strcmp(name, "BCURVE"))
		return vaar_data::CurveType::BCURVE_CURVE;
	if (0 == strcmp(name, "CIRCLE"))
		return vaar_data::CurveType::CIRCLE_CURVE;
	if (0 == strcmp(name, "CONST_PARAM"))
		return vaar_data::CurveType::CONST_PARAM_CURVE;
	if (0 == strcmp(name, "ELLIPSE"))
		return vaar_data::CurveType::ELLIPSE_CURVE;
	if (0 == strcmp(name, "INTERSECTION"))
		return vaar_data::CurveType::INTERSECTION_CURVE;
	if (0 == strcmp(name, "LINE"))
		return vaar_data::CurveType::LINE_CURVE;
	if (0 == strcmp(name, "SPCURVE"))
		return vaar_data::CurveType::SPCURVE_CURVE;
	if (0 == strcmp(name, "TRIMMED"))
		return vaar_data::CurveType::TRIMMED_CURVE;

	return vaar_data::CurveType::LINE_CURVE;
}

} // namespace vaar_file