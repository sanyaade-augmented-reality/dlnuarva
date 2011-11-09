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
//       ����ļ��������������������ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_COMPONENT_H_
#define VAARDATAMODEL_COMPONENT_H_

#include <memory>
#include <vector>

//����������
class vaar_data::Face;
class vaar_data::Edge;
class vaar_data::Vertex;

namespace vaar_data {

class Component {

public:
	// ���캯������������
	Component(const char* id, 
		      const char* name, 
			  const std::vector<Face*>* faces,
			  const std::vector<Edge*>* edges,
			  const std::vector<Vertex*>* vertices) {
		SetID(name);
		SetName(name);
		SetFaces(faces);
		SetEdges(edges);
		SetVertices(vertices);
	}
	~Component();

	// getter and setter
	void SetID(const char* id) {
		id_ = id;
	}
	char* GetID() {
		return id_._Get();
	}

	void SetName(const char* name) {
		name_ = name;
	}
	char* GetName() {
		return name_._Get();
	}

	void SetFaces(const std::vector<Face*>* faces) {
		faces_ = faces;
	}
	std::vector<Face*>* GetFaces() {
		return faces_.get();
	}

	void SetEdges(const std::vector<Edge*>* edges) {
		edges_ = edges;
	}
	std::vector<Edge*>* GetEdges() {
		return edges_.get();
	}

	void SetVertices(const std::vector<Vertex*>* vertices) {
		vertices_ = vertices;
	}
	std::vector<Vertex*>* GetVertices() {
		return vertices_.get();
	}
private:
	// ID
	std::tr1::shared_ptr<char*> id_;
	// ����
	std::tr1::shared_ptr<char*> name_;
	// ���
	std::tr1::shared_ptr<std::vector<Face*>*> faces_;
	// �߱�
	std::tr1::shared_ptr<std::vector<Edge*>*> edges_;
	// ���
	std::tr1::shared_ptr<std::vector<Vertex*>*> vertices_;

	// ��������
	// ��������
	// ��������
}; // class component

} // namespace vaar_data
#endif