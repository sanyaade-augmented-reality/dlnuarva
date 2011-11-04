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
//   File: /FileReader/FileReader.h
//         This file define a interface for reading the assembly file.
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_FILEREADER_H_
#define FILEREADER_FILEREADER_H_

namespace vaar_file {

class FileReader {
public:
	virtual __declspec(dllexport) char* Read(const char* file_path) = 0;
};

} // namespace vaar_file

#endif