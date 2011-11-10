//////////////////////////////////////////////////////////////////////////
// 版权声明 (C) 2011  大连民族学院
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
// 作者: Yang Yu, alex890714@gmail.com
// 文件: /VAARDataModel/Component.h
//       这个文件声明组件（零件）数据类。
// 修改历史：
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_COMPONENT_H_
#define VAARDATAMODEL_COMPONENT_H_

#include <memory>
#include <vector>
#include <string>

namespace vaar_data {

//声明并引入
class Face;
class Edge;
class Vertex;

class Component {

public:
	// 构造函数和析构函数
	Component(){}
	Component(const char* id, 
		      const char* name, 
			  std::vector<Face*>* faces,
			  std::vector<Edge*>* edges,
			  std::vector<Vertex*>* vertices) {
		SetID(name);
		SetName(name);
		SetFaces(faces);
		SetEdges(edges);
		SetVertices(vertices);
	}
	~Component(){}

	// getter and setter
	void SetID(const char* id) {
		id_ = std::tr1::shared_ptr<std::string>(new std::string(id));
	}
	const char* GetID() {
		return id_.get()->c_str();
	}

	void SetName(const char* name) {
		name_ = std::tr1::shared_ptr<std::string>(new std::string(name));
	}
	const char* GetName() {
		return name_._Get()->c_str();
	}

	void SetFaces(std::vector<Face*>* faces) {
		faces_ = std::tr1::shared_ptr<std::vector<Face*>>(faces);
	}
	const std::vector<Face*>* GetFaces() {
		return faces_.get();
	}

	void SetEdges(std::vector<Edge*>* edges) {
		edges_ = std::tr1::shared_ptr<std::vector<Edge*>>(edges);
	}
	const std::vector<Edge*>* GetEdges() {
		return edges_.get();
	}

	void SetVertices(std::vector<Vertex*>* vertices) {
		vertices_ = std::tr1::shared_ptr<std::vector<Vertex*>>(vertices);
	}
	const std::vector<Vertex*>* GetVertices() {
		return vertices_.get();
	}

	void SetSubComponents(std::vector<Component*>* sub_components) {
		sub_components_ = std::tr1::shared_ptr<std::vector<Component*>>(sub_components);
	}
	const std::vector<Component*>* GetSubComponents() {
		return sub_components_.get();
	}

private:
	// ID
	std::tr1::shared_ptr<std::string> id_;
	// 名称
	std::tr1::shared_ptr<std::string> name_;
	// 面表
	std::tr1::shared_ptr<std::vector<Face*>> faces_;
	// 边表
	std::tr1::shared_ptr<std::vector<Edge*>> edges_;
	// 点表
	std::tr1::shared_ptr<std::vector<Vertex*>> vertices_;
	// 子装配体
	std::tr1::shared_ptr<std::vector<Component*>> sub_components_;

	// 包围盒
	// 局部坐标系到世界坐标系的转换矩阵
	// 物理属性
	// 工程属性
	// 环境属性
}; // class component

} // namespace vaar_data
#endif