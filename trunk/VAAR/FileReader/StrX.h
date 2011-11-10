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
// �ļ�: /FileReader/StrX.h
//       ����ļ�������һ�����Խ�XMLCh(UTF16)���͵�����ת��Ϊ�������ݵ��ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_STRX_H
#define FILEREADER_STRX_H

#include <xercesc/util/XercesDefs.hpp>

namespace vaar_file {

// ����һ���򵥵��࣬�����������ɵĽ�XMLCh��UTF16�����͵������ڱ��������
class StrX {
public :
	// ���캯����
	// ����XMLCh�ַ�������xercesc������ṩ�ķ�������ת����
	// ��������fLocalForm��Ա�����С�
	StrX(const XMLCh* const toTranscode)
	{
		fLocalForm = xercesc::XMLString::transcode(toTranscode);
	}

	//��������
	~StrX()
	{
		xercesc::XMLString::release(&fLocalForm);
	}

	// ��ȡת����ı���char���顣
	const char* LocalForm() const
	{
		return fLocalForm;
	}

private :
	// �洢ת����ı����ַ�����
	char*   fLocalForm;
};

// ����������
inline XERCES_STD_QUALIFIER ostream& operator<<(XERCES_STD_QUALIFIER ostream& target, const StrX& toDump) {
	target << toDump.LocalForm();
	return target;
}

} // namespace vaar_file

#endif