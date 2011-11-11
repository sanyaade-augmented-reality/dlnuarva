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
// ����: Yang Yu, alex890714@gmail.com
// �ļ�: /VAARDataModel/Component.h
//       ����ļ�����������ģ���ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_DATAMODEL_H_
#define VAARDATAMODEL_DATAMODEL_H_

#include <memory>
#include <vector>
#include <hash_map>

#include <osg\Array>
#include <osg\ref_ptr>

namespace vaar_data {

//����������
class Component;
class Mate;

// ����ģ����
// ��װ��װ������ģ�ͣ���ʾ����ģ�ͣ���ײ�������ģ��
// �Լ�ģ��֮��Ĺ�ϵ
class DataModel {

public:
	// ���캯�����鹹����
	DataModel(){}
	DataModel(
		      Component* root,
			  std::vector<Mate*>* mates,
			  osg::Vec3Array* triangles,
			  osg::Vec3Array* normals,
			  std::hash_map<char*, Component*>* relation_map) {
		SetRoot(root);
		SetMates(mates);
		SetTriangles(triangles);
		SetNormals(normals);
		SetRelation(relation_map);
	}
	~DataModel(){}

	// getter and setter
	// ����װ��ģ����
	void SetRoot(Component* root) {
		root_ = std::tr1::shared_ptr<Component>(root);
	}
	// ��ȡװ��ģ�������ڵ�
	Component* GetRoot() {
		return root_.get();
	}

	void SetMates(std::vector<Mate*>* mates) {
		mates_ = std::tr1::shared_ptr<std::vector<Mate*>>(mates);
	}
	std::vector<Mate*>* GetMates() {
		mates_.get();
	}

	void SetTriangles(osg::Vec3Array* triangles) {
		triangle_vertices_ = osg::ref_ptr<osg::Vec3Array>(triangles);
	}
	osg::Vec3Array* GetTriangles() {
		return triangle_vertices_.get();
	}

	void SetNormals(osg::Vec3Array* normals) {
		triangle_normals_ = osg::ref_ptr<osg::Vec3Array>(normals);
	}
	osg::Vec3Array* GetNormals() {
		return triangle_normals_.get();
	}

	void SetRelation(std::hash_map<char*, Component*>* relation_map) {
		component_parent_map_ = std::tr1::shared_ptr<std::hash_map<char*, Component*>>(relation_map);
	}
	std::hash_map<char*, Component*>* GetRelation() {
		return component_parent_map_.get();
	}

private:
	// װ������ģ�͵ĸ��ڵ㣨�������˽ṹ��
	std::tr1::shared_ptr<Component> root_;
	// ����б�
	std::tr1::shared_ptr<std::vector<Mate*>> mates_;
	// ������Ƭ�����б�
	osg::ref_ptr<osg::Vec3Array> triangle_vertices_;
	// ������Ƭ���㷨�����б�
	osg::ref_ptr<osg::Vec3Array> triangle_normals_;
	// ComponentID, EdgeID, VertexID, FaceID�����ڵ��ӳ���ϵ
	std::tr1::shared_ptr<std::hash_map<char*, Component*>> component_parent_map_;
	// ����ӳ���ϵ

}; // class DataModel

} // namespace vaar_data
#endif