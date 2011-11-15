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
// �ļ�: /FileReader/DataModelInputDecorater/CurveInputDecorater.h
//       ����ļ�������һ���������XML�ļ�����䵽Curve�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_DATAMODELINPUTDECORATOR_CURVEINPUTDECORATOR_H_
#define FILEREADER_DATAMODELINPUTDECORATOR_CURVEINPUTDECORATOR_H_

#include <memory>

#include "InputDecorator.h"
#include "../../VAARDataModel/Curve.h"

namespace vaar_file {

// // �������Curve�ڵ��XML���ݣ�����䵽Curve����
class CurveInputDecorator : public InputDecorator{

public:
	// ���캯������������
	CurveInputDecorator(){}
	~CurveInputDecorator(){}

	// ����Edge�ڵ��XML���ݣ�����䵽Edge����
	virtual void Parse(const char *id, xercesc::DOMElement* element);
	// ��ȡEdge�����ָ��
	vaar_data::Curve* GetCurve();

private:
	// ��ȡCurveType
	vaar_data::CurveType GetCurveType(const char* name);

	// �������
	std::tr1::shared_ptr<vaar_data::Curve> curve_;

}; // class CurveInputDecorator

} // namespace vaar_file

#endif

