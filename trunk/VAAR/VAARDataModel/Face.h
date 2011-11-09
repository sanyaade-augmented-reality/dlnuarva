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

//����������Surface��
class vaar_data::Surface;

namespace vaar_data {

// ������
class Face {
public:
	// ���캯������������
    Face(const char* id, 
		 const Surface* surface, 
		 const std::vector<int>* triangles) {
		SetID(id);
		SetSurface(surface);
		SetTriangles(triangles);
	}
	~Face();

	// getter and setter
	void SetID(const char* id) {
		id_ = id;
	}
	char* GetID() {
		return id_.get();
	}

	void SetSurface(const Surface* surface) {
		surface_ = surface;
	}
	Surface* GetSurface() {
		return surface_.get();
	}

	void SetTriangles(const std::vector<int>* triangles) {
		triangles_ = triangles;
	}
	std::vector<int>* GetTriangles() {
		return triangles_.get();
	}

	void SetNormals(const std::vector<int>* normals) {
		normals_ = normals;
	}
	std::vector<int>* GetNormals() {
		return normals_;
	}
private:
	// ID
	std::tr1::shared_ptr<char*> id_;
	// ������Ϣ��
	std::tr1::shared_ptr<Surface*> surface_;
	// ������Ƭ������
	std::tr1::shared_ptr<std::vector<int>*> triangles_;
	// ������Ƭÿһ�������������
	std::tr1::shared_ptr<std::vector<int>*> normals_;
};

} // namespace vaar_data

#endif 
