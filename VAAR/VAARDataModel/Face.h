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
// �ļ�: /VAARDataModel/Face.h
//       ����ļ������˱��������ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_FACE_H_
#define VAARDATAMODEL_FACE_H_

#include <memory>
#include <vector>
#include <string>

namespace vaar_data {

//����������Surface��
class Surface;

// ������
class Face {
public:
	// ���캯������������
	Face(){}
	Face(const char* id, 
		 Surface* surface, 
		 std::vector<int>* triangles,
		 std::vector<int>* normals) {
		SetID(id);
		SetSurface(surface);
		SetTriangles(triangles);
		SetNormals(normals);
	}
	~Face(){}

	// getter and setter
	void SetID(const char* id) {
		id_ = std::tr1::shared_ptr<std::string>(new std::string(id));
	}
	char* GetID() {
		return (char*)id_.get()->c_str();
	}

	void SetSurface(Surface* surface) {
		surface_ = std::tr1::shared_ptr<Surface>(surface);
	}
	Surface* GetSurface() {
		return surface_.get();
	}

	void SetTriangles(std::vector<int>* triangles) {
		triangles_ = std::tr1::shared_ptr<std::vector<int>>(triangles);
	}
	std::vector<int>* GetTriangles() {
		return triangles_.get();
	}

	void SetNormals(std::vector<int>* normals) {
		normals_ = std::tr1::shared_ptr<std::vector<int>>(normals);
	}
	std::vector<int>* GetNormals() {
		return normals_.get();
	}
private:
	// ID
	std::tr1::shared_ptr<std::string> id_;
	// ������Ϣ��
	std::tr1::shared_ptr<Surface> surface_;
	// ������Ƭ������
	std::tr1::shared_ptr<std::vector<int>> triangles_;
	// ������Ƭÿһ�������������
	std::tr1::shared_ptr<std::vector<int>> normals_;
	// ��Χ��
};

} // namespace vaar_data

#endif 
