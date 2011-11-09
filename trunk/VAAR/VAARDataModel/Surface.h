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
// �ļ�: /VAARDataModel/Surface.h
//       ����ļ������˱��������࣬Surface��Face�ļ�����Ϣ��
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_SURFACE_H_
#define VAARDATAMODEL_SURFACE_H_

#define SURFACE_PARAMS_LENGTH 8

#include <memory>
#include <string>

namespace vaar_data {

// Surface����Face��ļ�����Ϣ���������ΪFace�ĳ�Ա������
class Surface {
public:
	// ���캯������������
	Surface(const char* id, const SurfaceType type, const double params[SURFACE_PARAMS_LENGTH]) {
		SetID(id);
		SetSurfaceType(type);
		SetParams(params);
	}
	~Surface();

	// getter and setter
	// ����params����
	void SetParams(const double params[SURFACE_PARAMS_LENGTH] ) {
		for (int i = 0; i < SURFACE_PARAMS_LENGTH; ++i)
			params_[i] = params[i];
	}
	// ����һ������Ϊ8��params���飬size�泤�ȡ�
	const double* GetParams(int &size) {
		size = SURFACE_PARAMS_LENGTH;
		return params_;
	}

	void SetSurfaceType(const SurfaceType type) {
		type_ = type;
	}
	const SurfaceType GetSurfaceType() {
		return type_;
	}

	void SetID(const char* id) {
		id_ = std::tr1::shared_ptr<std::string>(new std::string(id));
	}
	const char* GetID() {
		return id_.get()->c_str();
	}
private:
	//ID
	std::tr1::shared_ptr<std::string> id_;
	//����
	SurfaceType type_;
	//����
	double params_[SURFACE_PARAMS_LENGTH];

}; // class Surface.

// Surface���͵�ö�١�
enum SurfaceType {
	PLANE,
	CYLINDER,
	CONE,
	SPHERE,
	TORUS,
	BSURF,
	BLEND,
	OFFSET,
	EXTRU,
	SREV
};  // enum SurfaceType

} // namespace vaar_data

#endif 