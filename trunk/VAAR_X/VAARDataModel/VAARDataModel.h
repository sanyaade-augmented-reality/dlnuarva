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
// �ļ�: /VAARDataModel/VAARDataModel.h
//       ����ļ����������ݰ�����ڡ�
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////
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

// ������Ϊ��ں������࣬�����κ�����
class VAARDataModel {
public:
	VAARDataModel(){}
	~VAARDataModel(){}
	__declspec(dllexport) void Main();
}; // class VAARDataModel

}; // namespace vaar_data.

#endif