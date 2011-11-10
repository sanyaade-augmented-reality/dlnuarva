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
// �ļ�: /VAARDataModel/Component.h
//       ����ļ�����������ģ���ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#ifndef VAARDATAMODEL_DATAMODEL_H_
#define VAARDATAMODEL_DATAMODEL_H_

#include <memory>
#include <vector>
#include <hash_map>

#include <osg\Array>
#include <osg\ref_ptr>

namespace vaar_data {

//����������
class Component;
class Mate;

// ����ģ����
// ��װ��װ������ģ�ͣ���ʾ����ģ�ͣ���ײ�������ģ��
// �Լ�ģ��֮��Ĺ�ϵ
class DataModel {
public:
	__declspec(dllexport) void Test();
private:
	// װ������ģ�͵�ͷ�ڵ㣨�������˽ṹ��
	std::tr1::shared_ptr<Component> header_;
	// ����б�
	std::tr1::shared_ptr<std::vector<Mate*>> mates_;
	// ������Ƭ�����б�
	osg::ref_ptr<osg::Vec3Array> triangle_vertices_;
	// ������Ƭ���㷨�����б�
	osg::ref_ptr<osg::Vec3Array> triangle_normals_;
}; // class DataModel

} // namespace vaar_data
#endif