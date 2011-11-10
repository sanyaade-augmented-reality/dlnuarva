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
// ����: ����, alex890714@gmail.com
// �ļ�: /FileReader/DataModelInputDecorater/InputDecorater.h
//       ����ļ������˽���XML���ݲ���䵽�������͵Ľӿڡ�
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_DATAMODELINPUTDECORATOR_INPUTDECORATOR_H_
#define FILEREADER_DATAMODELINPUTDECORATOR_INPUTDECORATOR_H_

#include <xercesc/dom/DOMElement.hpp>

namespace vaar_file {

// ��������ӿ�
class InputDecorator {
public:
	virtual void Parse(const char* id, xercesc::DOMElement* element) = 0;
}; // class InputDecorator
}; // namespace vaar_file
#endif