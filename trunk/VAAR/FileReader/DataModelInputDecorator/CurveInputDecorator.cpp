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

}

// ��ȡCurve�����ָ��
vaar_data::Curve* CurveInputDecorator::GetCurve() {
	return curve_.get();
}

} // namespace vaar_file