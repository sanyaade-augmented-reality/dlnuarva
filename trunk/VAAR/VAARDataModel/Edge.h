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
// �ļ�: /VAARDataModel/Edge.h
//       ����ļ��������߶������ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_EDGE_H_
#define VAARDATAMODEL_EDGE_H_

#define EDGE_PARAMS_LENGTH 11

#include <memory>
#include <string>

namespace vaar_data {

//����������Curve��
class Curve;
	
//�߶���
class Edge {
public:
	// ���캯������������
	Edge(){}
	Edge(const char* id, Curve* curve, const double params[EDGE_PARAMS_LENGTH]) {
		SetID(id);
		SetCurve(curve);
		SetParams(params);
	}
	~Edge(){}

	// getter and setter
	// ����params����
	void SetParams(const double params[EDGE_PARAMS_LENGTH]) {
		for (int i = 0; i < EDGE_PARAMS_LENGTH; ++i)
			params_[i] = params[i];
	}
	// ����һ������Ϊ11��params���飬size�泤�ȡ�
	double* GetParams(int &size) {
		size = EDGE_PARAMS_LENGTH;
		return params_;
	}

	void SetCurve(Curve* curve) {
		curve_ = std::tr1::shared_ptr<Curve>(curve);
	}
	Curve* GetCurve() {
		return curve_.get();
	}

	void SetID(const char* id) {
		id_ = std::tr1::shared_ptr<std::string>(new std::string(id));
	}
	char* GetID() {
		return (char*)id_.get()->c_str();
	}

private:
	//ID
	std::tr1::shared_ptr<std::string> id_;
	//������Ϣ
	std::tr1::shared_ptr<Curve> curve_;
	//����
	double params_[EDGE_PARAMS_LENGTH];
}; // class Edge

} // namespace vaar_data
#endif