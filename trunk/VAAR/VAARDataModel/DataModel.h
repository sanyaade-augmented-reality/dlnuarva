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
// 文件: /VAARDataModel/Component.h
//       这个文件声明了数据模型类。
// 修改历史：
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_DATAMODEL_H_
#define VAARDATAMODEL_DATAMODEL_H_

#include <memory>
#include <vector>
#include <hash_map>

#include <osg\Array>
#include <osg\ref_ptr>

namespace vaar_data {

//声明并引入
class Component;
class Mate;

// 数据模型类
// 封装了装配数据模型，显示数据模型，碰撞检测数据模型
// 以及模型之间的关系
class DataModel {
public:
	__declspec(dllexport) void Test();
private:
	// 装配数据模型的头节点（树形拓扑结构）
	std::tr1::shared_ptr<Component> header_;
	// 配合列表
	std::tr1::shared_ptr<std::vector<Mate*>> mates_;
	// 三角面片顶点列表
	osg::ref_ptr<osg::Vec3Array> triangle_vertices_;
	// 三角面片顶点法向量列表
	osg::ref_ptr<osg::Vec3Array> triangle_normals_;
}; // class DataModel

} // namespace vaar_data
#endif