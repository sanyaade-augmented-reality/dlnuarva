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
// �ļ�: /FileReader/DataModelInputDecorater/EdgeInputDecorater.cpp
//       ����ļ�ʵ����һ���������XML�ļ�����䵽Edge�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#include <cstring>

#include <xercesc/util/XMLString.hpp>

#include "EdgeInputDecorator.h"
#include "CurveInputDecorator.h"

namespace vaar_file {

// �����DOMģ��Ϊ
// <SWEdge>
// 	<ID>0</ID>
// 	<Curve />
// 		<Params> 
// 			<double>0.049999999999999989</double> 
// 			<double>0.059999999999999984</double> 
// 			<double>0.069999999999999993</double> 
// 			<double>0.049999999999999989</double> 
// 			<double>0.059999999999999984</double> 
// 			<double>0</double> 
// 			<double>0.020000000000000004</double> 
// 			<double>0.09</double> 
// 			<double>6.36810936868678E-311</double> 
// 			<double>7.87260438448116E-312</double> 
// 			<double>0</double> 
// 		</Params> 
// </SWEdge>
void EdgeInputDecorator::Parse(const char *id, xercesc::DOMElement* element) {
	if (NULL == element)
		return;

	vaar_data::Curve* curve = NULL;
	double params[EDGE_PARAMS_LENGTH];
	int i = 0;
	xercesc::DOMElement* current_element = NULL;
	CurveInputDecorator* input = NULL;

	// ����Curve ID
	std::string curve_id(id);
	curve_id += "_curve";

	// ����Curve
	element = element->getFirstElementChild();
	element = element->getNextElementSibling();
	if (NULL != element &&
		0 == strcmp("Curve", xercesc::XMLString::transcode(element->getTagName()))) {
		input = new CurveInputDecorator();
		input->Parse(curve_id.c_str(), element);
		curve = input->GetCurve();
	}

	// ����Params
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

// 	if (NULL != input)
// 		delete input;

	edge_ = std::tr1::shared_ptr<vaar_data::Edge>(new vaar_data::Edge(id, curve, params));
}

// ��ȡEdge�����ָ��
vaar_data::Edge* EdgeInputDecorator::GetEdge() {
	return edge_.get();
}

} // namespace vaar_file