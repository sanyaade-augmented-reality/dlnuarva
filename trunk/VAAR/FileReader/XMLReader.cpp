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
// �ļ�: /FileReader/XMLReader.cpp
//       ����ļ�ʵ����XMLReader�ࡣ
// �޸���ʷ��
///////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/sax/HandlerBase.hpp>

#include "XMLReader.h"
#include "StrX.h"
#include "DataModelInputDecorator/InputDecorator.h"
#include "DataModelInputDecorator/VertexInputDecorator.h"

namespace vaar_file {
// 
// void Traverse(xercesc::DOMElement *element) {
// 	if (NULL == element)
// 		return;
// 
// 	std::cout << StrX(element->getTagName()) << "\n";
// 
// 	Traverse(element->getFirstElementChild());
// 
// 	element = element->getNextElementSibling();
// 	while (NULL != element) {
// 		Traverse(element);
// 		element = element->getNextElementSibling();
// 	}
// }

__declspec(dllexport) void XMLReader::Read(const char* file_path) {
	try {
		// ��ʼ��xerces
		xercesc::XMLPlatformUtils::Initialize();
   
		xercesc::XercesDOMParser *parser = new xercesc::XercesDOMParser();
		if (NULL == parser)
			return;

		// ����
		parser->setValidationScheme(xercesc::XercesDOMParser::Val_Auto);
		parser->setDoNamespaces(false);
		parser->setDoSchema(false);

		// ���ô�����
		xercesc::ErrorHandler* errHandler = (xercesc::ErrorHandler*) new xercesc::HandlerBase();
		parser->setErrorHandler(errHandler);

		// �����ļ�
		parser->parse(file_path);
		
		// ��ȡDOM�ĵ�ģ��
		xercesc::DOMDocument* document = parser->getDocument();
		if (NULL == document) {
			parser->adoptDocument();
			delete errHandler;
			delete parser;
			return;
		}

		// get element.
		xercesc::DOMElement* element = document->getDocumentElement();
		if (NULL == document) {
			parser->adoptDocument();
			delete errHandler;
			delete parser;
			return;
		}

		xercesc::DOMNodeList* list = element->getElementsByTagName(xercesc::XMLString::transcode("SubComponents"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		list = element->getElementsByTagName(xercesc::XMLString::transcode("SWComponent"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		list = element->getElementsByTagName(xercesc::XMLString::transcode("Bodies"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		list = element->getElementsByTagName(xercesc::XMLString::transcode("SWVertex"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		
		std::cout << StrX(element->getTagName()) << "\n";
		std::cout << StrX(element->getTextContent()) << "\n";

		VertexInputDecorator* input = new VertexInputDecorator();
		input->Parse("", element);
		vaar_data::Vertex* vertex = input->GetVertex();

		std::cout << vertex->GetX() << "\n";
		std::cout << vertex->GetY() << "\n";
		std::cout << vertex->GetZ() << "\n";

// 		for (XMLSize_t i = 0; i < list->getLength(); ++i) {
// 			xercesc::DOMNode* node = list->item(i);
// 			xercesc::DOMElement* ele = dynamic_cast<xercesc::DOMElement*>(node);
// 			std::cout << StrX(ele->getTagName()) << "\n";
// 		}

		
		//Traverse(element);

		parser->adoptDocument();
		delete document;
		delete errHandler;
		delete parser;
	} catch (const xercesc::XMLException& toCatch) {	
		std::cerr << "Exception message is: \n"
			<< StrX(toCatch.getMessage()) << "\n";
		return;
	} catch (const xercesc::DOMException& toCatch) {
		std::cerr << "Exception message is: \n"
			<< StrX(toCatch.getMessage()) << "\n";
		return;
	}
	
	xercesc::XMLPlatformUtils::Terminate();
};

} // namespace vaar_file