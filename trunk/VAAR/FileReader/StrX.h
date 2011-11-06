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
//   File: /FileReader/StrX.h
//         This file define a class for converting the XMLCh data to 
//         local code page for display.
///////////////////////////////////////////////////////////////////////////

#ifndef FILEREADER_STRX_H
#define FILEREADER_STRX_H

#include <xercesc/util/XercesDefs.hpp>

namespace vaar_file {


//  This is a simple class that lets us do easy (though not terribly efficient)
//  trancoding of XMLCh data to local code page for display.
class StrX {
public :
	//  Constructors and Destructor
	StrX(const XMLCh* const toTranscode)
	{
		// Call the private transcoding method
		fLocalForm = xercesc::XMLString::transcode(toTranscode);
	}

	~StrX()
	{
		xercesc::XMLString::release(&fLocalForm);
	}

	//  Getter methods
	const char* LocalForm() const
	{
		return fLocalForm;
	}

private :
	// -----------------------------------------------------------------------
	//  Private data members
	//
	//  fLocalForm
	//      This is the local code page form of the string.
	// -----------------------------------------------------------------------
	char*   fLocalForm;
};

inline XERCES_STD_QUALIFIER ostream& operator<<(XERCES_STD_QUALIFIER ostream& target, const StrX& toDump) {
	target << toDump.LocalForm();
	return target;
}

} // namespace vaar_file

#endif