//////////////////////////////////////////////////////////////////////////
// Copyright (C) 2011  Dalian Nationalities University
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
// Author: Yang Yu, alex890714@gmail.com
//   File: /FileReader/XMLReader.cpp
//         This file implement a class for reading the assembly file of the xml 
//         format.
///////////////////////////////////////////////////////////////////////////

#include "XMLReader.h"
#include <xercesc/util/PlatformUtils.hpp>

namespace vaar_file {

__declspec(dllexport) char* XMLReader::Read(const char* file_path) {
	try
	{
		xercesc::XMLPlatformUtils::Initialize();
	}
	catch (const xercesc::XMLException& toCatch)
	{
		
	}
	
	xercesc::XMLPlatformUtils::Terminate();

	return "Hello";
};

} // namespace vaar_file