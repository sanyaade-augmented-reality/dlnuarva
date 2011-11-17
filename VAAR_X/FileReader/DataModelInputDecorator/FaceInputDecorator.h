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
// �ļ�: /FileReader/DataModelInputDecorater/FaceInputDecorater.h
//       ����ļ�������һ���������XML�ļ�����䵽Face�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_DATAMODELINPUTDECORATOR_FACEINPUTDECORATOR_H_
#define FILEREADER_DATAMODELINPUTDECORATOR_FACEINPUTDECORATOR_H_

#include <memory>

#include <osg/ref_ptr>
#include <osg/Array>

#include "InputDecorator.h"
#include "../../VAARDataModel/Face.h"

namespace vaar_file {

// �������SWFace�ڵ��XML���ݣ�����䵽Face����
class FaceInputDecorator : public InputDecorator {

public:
	// ���캯������������
	FaceInputDecorator(osg::ref_ptr<osg::Vec3Array>& vertices, osg::ref_ptr<osg::Vec3Array>& normals) {
		vertices_ = vertices;
		normals_ = normals;
	}
	FaceInputDecorator() {}
	~FaceInputDecorator() {}

	// ����SWFace�ڵ��XML���ݣ�����䵽Face����
	virtual void Parse(const char* id, xercesc::DOMElement* element);
	// ��ȡFace����ָ��
	vaar_data::Face* GetFace();
private:
	// �������
	std::tr1::shared_ptr<vaar_data::Face> face_;
	// ���Ƕ����б���
	osg::ref_ptr<osg::Vec3Array> vertices_;
	// ���Ƕ��㷨�����б���
	osg::ref_ptr<osg::Vec3Array> normals_;
}; // class FaceInputDecorator

} // namespace vaar_file

#endif