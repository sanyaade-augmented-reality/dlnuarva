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
// 作者: 杨雨, alex890714@gmail.com
// 文件: /FileReader/DataModelInputDecorater/EdgeInputDecorater.cpp
//       这个文件实现了一个负责解析XML文件并填充到Edge数据类型的类。
// 修改历史：
///////////////////////////////////////////////////////////////////////////

#include <cstring>

#include <xercesc/util/XMLString.hpp>

#include "EdgeInputDecorator.h"

namespace vaar_file {

//
void EdgeInputDecorator::Parse(const char *id, xercesc::DOMElement* element) {

}

// 获取Edge对象的指针
vaar_data::Edge* EdgeInputDecorator::GetEdge() {
	return edge_.get();
}

} // namespace vaar_file