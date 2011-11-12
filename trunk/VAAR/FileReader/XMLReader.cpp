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
// 文件: /FileReader/XMLReader.cpp
//       这个文件实现了XMLReader类。
// 修改历史：
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
#include "DataModelInputDecorator/CurveInputDecorator.h"
#include "DataModelInputDecorator/EdgeInputDecorator.h"
#include "DataModelInputDecorator/SurfaceInputDecorator.h"
#include "DataModelInputDecorator/FaceInputDecorator.h"

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
		// 初始化xerces
		xercesc::XMLPlatformUtils::Initialize();
   
		xercesc::XercesDOMParser *parser = new xercesc::XercesDOMParser();
		if (NULL == parser)
			return;

		// 配置
		parser->setValidationScheme(xercesc::XercesDOMParser::Val_Auto);
		parser->setDoNamespaces(false);
		parser->setDoSchema(false);

		// 配置错误处理
		xercesc::ErrorHandler* errHandler = (xercesc::ErrorHandler*) new xercesc::HandlerBase();
		parser->setErrorHandler(errHandler);

		// 解析文件
		parser->parse(file_path);
		
		// 获取DOM文档模型
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

		/* Test VertexInputDecorator
		list = element->getElementsByTagName(xercesc::XMLString::transcode("SWVertex"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		*/

		/* Test CurveInputDecorator
		list = element->getElementsByTagName(xercesc::XMLString::transcode("Curve"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		*/

		/* Test EdgeInputDecoratorTest
		list = element->getElementsByTagName(xercesc::XMLString::transcode("SWEdge"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		*/

		/* Test SurfaceInputDecoratorTest
		list = element->getElementsByTagName(xercesc::XMLString::transcode("Surface"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		*/ 

		/* Test FaceInputDecoratorTest
		list = element->getElementsByTagName(xercesc::XMLString::transcode("SWFace"));
		element = dynamic_cast<xercesc::DOMElement*>(list->item(0));
		
		std::cout << StrX(element->getTagName()) << "\n";
		std::cout << StrX(element->getTextContent()) << "\n";
		*/

		/* Test VertexInputDecorator
		VertexInputDecorator* input = new VertexInputDecorator();
		input->Parse("", element);
		vaar_data::Vertex* vertex = input->GetVertex();

		std::cout << vertex->GetX() << "\n";
		std::cout << vertex->GetY() << "\n";
		std::cout << vertex->GetZ() << "\n";
		*/

		/* Test CurveInputDecorator
		CurveInputDecorator* input = new CurveInputDecorator();
		input->Parse("", element);
		vaar_data::Curve* curve = input->GetCurve();

		int length;
		const double* params;
		std::cout << curve->GetCurveType() << "\n";
		params = curve->GetParams(length);

		for (int i = 0; i < length; ++i) {
			std::cout << params[i] << "\n";
		}
		*/

		/* Test EdgeInputDecoratorTest
		EdgeInputDecorator input;
		input.Parse("edge01", element);
		vaar_data::Edge* edge = input.GetEdge();
		vaar_data::Curve* curve = edge->GetCurve();
		
		std::cout << edge->GetID() << "\n";
		std::cout << curve->GetID() << "\n";

		int length;
		double* params;
		std::cout << curve->GetCurveType() << "\n";
		params = curve->GetParams(length);

		for (int i = 0; i < length; ++i) {
			std::cout << params[i] << "\n";
		}

		std::cout << "\n";

		params = edge->GetParams(length);

		for (int i = 0; i < length; ++i) {
			std::cout << params[i] << "\n";
		}
		*/

		/* Test SurfaceInputDecorator
		SurfaceInputDecorator input;
		input.Parse("test", element);
		vaar_data::Surface* surface = input.GetSurface();

		std::cout << surface->GetID() << "\n";
		int length;
		double* params;
		std::cout << surface->GetSurfaceType() << "\n";
		params = surface->GetParams(length);
		for (int i = 0; i < length; ++i) {
			std::cout << params[i] << "\n";
		}
		*/

		// Test FaceInputDecorator
		osg::ref_ptr<osg::Vec3Array> triangles = new osg::Vec3Array;
		osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
		FaceInputDecorator input(triangles, normals);
		input.Parse("face01", element);
		vaar_data::Face* face = input.GetFace();
		vaar_data::Surface* surface = face->GetSurface();

		// Output Surface
		std::cout << surface->GetID() << "\n";
		int length;
		double* params;
		std::cout << surface->GetSurfaceType() << "\n";
		params = surface->GetParams(length);
		for (int i = 0; i < length; ++i) {
			std::cout << params[i] << "\n";
		}

		// Output Face
		std::cout << face->GetID() << "\n";

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