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
// �ļ�: /FileReader/DataModelInputDecorater/ComponentInputDecorater.h
//       ����ļ�������һ���������XML�ļ�����䵽Component�������͵��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_DATAMODELINPUTDECORATOR_COMPONENTINPUTDECORATOR_H_
#define FILEREADER_DATAMODELINPUTDECORATOR_COMPONENTINPUTDECORATOR_H_

#include <memory>
#include <hash_map>

#include <osg/ref_ptr>
#include <osg/Array>

#include "InputDecorator.h"
#include "..\VAARDataModel\Component.h"

namespace vaar_file {

// �������SWComponent�ڵ��XML���ݣ�����䵽Face����
class ComponentInputDecorator : public InputDecorator{

public:
	// ���캯������������
	ComponentInputDecorator(
		osg::ref_ptr<osg::Vec3Array>& vertices, 
		osg::ref_ptr<osg::Vec3Array>& normals,
		std::tr1::shared_ptr<std::hash_map<std::string, vaar_data::Component*>>& component_parent_map) {
		vertices_ = vertices;
		normals_ = normals;
		component_parent_map_ = component_parent_map;
	}
	ComponentInputDecorator() {}
	~ComponentInputDecorator() {}

	// ����SWFace�ڵ��XML���ݣ�����䵽Face����
	virtual void Parse(const char* id, xercesc::DOMElement* element);
	// ��ȡFace����ָ��
	vaar_data::Component* GetComponent();
private:
	// �������
	std::tr1::shared_ptr<vaar_data::Component> component_;
	// ���Ƕ����б���
	osg::ref_ptr<osg::Vec3Array> vertices_;
	// ���Ƕ��㷨�����б���
	osg::ref_ptr<osg::Vec3Array> normals_;
	// ComponentID, EdgeID, VertexID, FaceID�����ڵ��ӳ���ϵ
	std::tr1::shared_ptr<std::hash_map<std::string, vaar_data::Component*>> component_parent_map_;

}; // class ComponentInputDecorator

} // namespace vaar_file

#endif