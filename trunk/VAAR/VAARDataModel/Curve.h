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
// 文件: /VAARDataModel/Curve.h
//       这个文件声明了曲线数据类，Curve是Edge的几何信息。
// 修改历史：
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_CURVE_H_
#define VAARDATAMODEL_CURVE_H_

#define CURVE_PARAMS_LENGTH 11

#include <memory>

namespace vaar_data {

class Curve  {
public:
	// 构造函数和析构函数
	Curve(const char* id, const CurveType type, const double[CURVE_PARAMS_LENGTH] params) {
		SetID(id);
		SetCurveType(type);
		SetParams(params);
	}
	~Curve();

	// getter and setter
	// 设置params属性
	void SetParams(const double[CURVE_PARAMS_LENGTH] params) {
		for (int i = 0; i < CURVE_PARAMS_LENGTH; ++i)
			params_[i] = params[i];
	}
	// 返回一个长度为11的params数组，size存长度。
	double* GetParams(int &size) {
		size = CURVE_PARAMS_LENGTH;
		return params_;
	}

	void SetCurveType(const CurveType type) {
		type_ = type;
	}
	SurfaceType GetCurveType() {
		return type_;
	}

	void SetID(const char* id) {
		id_ = id;
	}
	char* GetID() {
		return id_.get();
	}
private:
	//ID
	std::tr1::shared_ptr<char*> id_;
	//类型
	CurveType type_;
	//参数
	double params_[CURVE_PARAMS_LENGTH];

}; // class Curve

enum CurveType {
	LINE,
	CIRCLE,
	ELLIPSE,
	INTERSECTION,
	BCURVE,
	SPCURVE,
	CONST_PARAM,
	TRIMMED
};

}; // namespace vaar_data
#endif