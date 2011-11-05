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
#include <xercesc/util/XMLString.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/sax/HandlerBase.hpp>

#include <iostream>


namespace vaar_file {

__declspec(dllexport) void XMLReader::Read(const char* file_path) {
	try {
		// initialize the xerces.
		xercesc::XMLPlatformUtils::Initialize();
   
		xercesc::XercesDOMParser *parser = new xercesc::XercesDOMParser();
		if (NULL == parser)
			return;

		// configration.
		parser->setValidationScheme(xercesc::XercesDOMParser::Val_Auto);
		parser->setDoNamespaces(false);
		parser->setDoSchema(false);

		// error handling configuration.
		xercesc::ErrorHandler* errHandler = (xercesc::ErrorHandler*) new xercesc::HandlerBase();
		parser->setErrorHandler(errHandler);

		// parse file.
		parser->parse(file_path);
		
		// get document.
		xercesc::DOMDocument* document = parser->getDocument();
		if (NULL == document) {
			parser->adoptDocument();
			delete errHandler;
			delete parser;
			return;
		}

		// get elemet.
		xercesc::DOMElement *element = document->getDocumentElement();
		if (NULL == document) {
			parser->adoptDocument();
			delete errHandler;
			delete parser;
			return;
		}

		while (NULL != element) {
			
		}
		
		//delete element;
		parser->adoptDocument();
		delete document;
		delete errHandler;
		delete parser;
		
		
		
	} catch (const xercesc::XMLException& toCatch) {
		char* message = xercesc::XMLString::transcode(toCatch.getMessage());
		std::cerr << "Exception message is: \n"
			<< message << "\n";
		xercesc::XMLString::release(&message);
		return;
	} catch (const xercesc::DOMException& toCatch) {
		char* message = xercesc::XMLString::transcode(toCatch.msg);
		std::cerr << "Exception message is: \n"
			<< message << "\n";
		xercesc::XMLString::release(&message);
		return;
	}
	
	xercesc::XMLPlatformUtils::Terminate();
};

} // namespace vaar_file