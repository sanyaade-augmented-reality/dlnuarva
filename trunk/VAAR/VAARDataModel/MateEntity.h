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
// �ļ�: /VAARDataModel/MateEntity.h
//       ����ļ����������ʵ�������ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMEDEL_MATEENTITY_H_
#define VAARDATAMEDEL_MATEENTITY_H_

#define MATEENTITY_PARAMS_LENGTH 8

#include <memory>
#include <string>

namespace vaar_data {

// ����������Component��
class Component;

// ���ʵ�������
enum MateEntityType {
	POINT_MATEENTITY,
	LINE_MATEENTITY,
	PLANE_MATEENTITY,
	CYLINDER_MATEENTITY,
	CONE_MATEENTITY
}; // enum MateEntityType

// ���ʵ��
class MateEntity {

public:
	// ���캯������������
	MateEntity(const char* component_name, 
		       const double params[MATEENTITY_PARAMS_LENGTH] ,
			   const MateEntityType type) {
		SetComponentName(component_name);
		SetParams(params);
		SetMateEntityType(type);
	}
	~MateEntity();

	// getter and setter
	void SetComponentName(const char* name) {
		component_name_ = std::tr1::shared_ptr<std::string>(new std::string(name));
	}
	const char* GetComponentName() {
		return component_name_.get()->c_str();
	}

	// ���ò���
	void SetParams(const double params[MATEENTITY_PARAMS_LENGTH]) {
		for (int i = 0; i < MATEENTITY_PARAMS_LENGTH; ++i)
			params_[i] = params[i];
	}
	// ����һ������Ϊ8�Ĳ������飬size�泤�ȡ�
	const double* GetParams(int &size) {
		size = MATEENTITY_PARAMS_LENGTH;
		return params_;
	}

	void SetMateEntityType(const MateEntityType type) {
		type_ = type;
	}
	const MateEntityType GetMateEntityType() {
		return type_;
	}

	void SetComponent(Component* component) {
		component_  = std::tr1::shared_ptr<Component>(component);
	}
	const Component* GetComponent() {
		return component_.get();
	}

private:
	// ʵ���������������
	std::tr1::shared_ptr<std::string> component_name_;
	// ������
	std::tr1::shared_ptr<Component> component_;
	// ����
	double params_[MATEENTITY_PARAMS_LENGTH];
	// ����
	MateEntityType type_;
}; // class MateEntitu

} // namespace vaar_data
#endif