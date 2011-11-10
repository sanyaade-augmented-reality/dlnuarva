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
// �ļ�: /VAARDataModel/Mate.h
//       ����ļ���������������ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_MATE_H_
#define VAARDATAMODEL_MATE_H_

#include <memory>
#include <vector>
#include <string>

namespace vaar_data {

// ����������MateEntity��
class MateEntity;

// �������
enum MateType {
	// �غ�
	COINCIDENT_MATE,
	// ͬ��
	CONCENTRIC_MATE,
	// ��ֱ
	PERPENDICULAR_MATE,   
	// ƽ��
	PARALLEL_MATE,
	// ����
	TANGENT_MATE,
	// ����
	DISTANCE_MATE,
	// �Ƕ�
	ANGLE_MATE,
	// δ֪
	UNKNOWN_MATE,
	// �Գ�
	SYMMETRIC_MATE,
	// ͹�ֶ���
	CAMFOLLOWER_MATE,
	// ����
	GEAR_MATE,
	// ���
	WIDTH_MATE,
	// Lock to sketch
	LOCKTOSKETCH_MATE,
	// �����ͳ���
	RACKPINION_MATE,
	// Max Mates
	MAXMATES_MATE,
	// ·�����
	PATH_MATE,
	// ����
	LOCK_MATE,
	// �������
	SCREW_MATE,
	// ���������
	LINEARCOUPLER_MATE,
	// �����
	UNIVERSALJOINT_MATE,
	// ����ϵ
	COORDINATE_MATE,
	// ��
	SLOT_MATE,
	// ����
	HINGE_MATE,
	// ����
	SLIDER_MATE
}; // enum MateType

// ���������
class Mate {
public:
	// ���캯������������
	Mate(){}
	Mate(const char* id,
		 const MateType type,
		 const double min_variation,
		 const double max_variation,
		 std::vector<MateEntity*>* entities,
		 const bool flipped) {
		SetID(id);
		SetMateType(type);
		SetMaxVariation(max_variation);
		SetMinVariation(min_variation);
		SetMateEntities(entities);
		SetFlipped(flipped);
	}
	~Mate(){}

	// getter and setter
	void SetID(const char* id) {
		id_ = std::tr1::shared_ptr<std::string>(new std::string(id));
	}
	const char* GetID() {
		return id_.get()->c_str();
	}

	void SetMateType(const MateType type) {
		type_ = type;
	}
	const MateType GetMateType() {
		return type_;
	}

	void SetMinVariation(const double par_value) {
		min_variation_ = par_value;
	} 
	const double GetMinVariation() {
		return min_variation_;
	}

	void SetMaxVariation(const double par_value) {
		max_variation_ = par_value;
	} 
	const double GetMaxVariation() {
		return max_variation_;
	}

	void SetFlipped(const bool filpped) {
		is_flipped_ = filpped;
	}
	const bool GetFlipped() {
		return is_flipped_;
	}

	void SetMateEntities(std::vector<MateEntity*>* entities) {
		mate_entities_ = std::tr1::shared_ptr<std::vector<MateEntity*>>(entities);
	}
	const std::vector<MateEntity*>* GetMateEntities() {
		return mate_entities_.get();
	}
private:
	// ID
	std::tr1::shared_ptr<std::string> id_;
	// �������
	MateType type_;
	// ����ֵ
	double max_variation_;
	// ��С��ֵ
	double min_variation_;
	// ����ͽǶ��Ƿ�ת
	bool is_flipped_;

	// ��ϵ����ʵ��
	std::tr1::shared_ptr<std::vector<MateEntity*>> mate_entities_;
}; // class Mate

} // namespace vaar_data
#endif