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
// 文件: /FileReader/DataModelInputDecorater/ComponentInputDecorater.cpp
//       这个文件实现了一个负责解析XML文件并填充到Component数据类型的类。
// 修改历史：
///////////////////////////////////////////////////////////////////////////

#include "ComponentInputDecorator.h"

namespace vaar_file {

// 传入的DOM模型为
// <SWComponent> 
// 	<Name>Tutor2-1</Name> 
// 	<SubComponents/> 
// 	<IsRoot>false</IsRoot> 
// 	<BoundingBox>
// 	<Bodies>
// 		<SWBody> 
// 			<Name>切除-拉伸1</Name>
// 			<Faces>
// 			<Edges>
// 			<Vertices>
// 		</SWBody> 
// 	</Bodies> 
// </SWComponent>
void ComponentInputDecorator::Parse(const char* id, xercesc::DOMElement* element) {
	if (NULL == element || !vertices_.valid() || !normals_.valid())
		return;
}

// 返回
vaar_data::Component* ComponentInputDecorator::GetComponent() {
	return component_.get();
}

} // namespace vaar_file