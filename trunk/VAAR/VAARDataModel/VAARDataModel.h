#ifndef VAARDATAMODEL_VAARDATEMODEL_H_
#define VAARDATAMODEL_VAARDATEMODEL_H_

#include "DataModel.h"
#include "Component.h"
#include "Curve.h"
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include "Surface.h"
#include "Mate.h"
#include "MateEntity.h"

namespace vaar_data {

// 此类作为入口函数的类，不起任何作用
class VAARDataModel {
	__declspec(dllexport) void Main();
}; // class VAARDataModel

}; // namespace vaar_data.

#endif