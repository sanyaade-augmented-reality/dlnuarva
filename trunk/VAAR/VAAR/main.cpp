#include <osgViewer/Viewer>
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/ref_ptr>
#include <osg/PrimitiveSet>

#include "XMLReader.h"
#include "FileReader.h"
#include "../VAARDataModel/DataModel.h"
#include "../VAARDataModel/Component.h"

osg::Geometry* CreatGeometry(vaar_data::Component* component) {
	osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	
	geometry->setVertexArray(component->GetRefPtrTriangles().get());
	
	geometry->setNormalArray(component->GetRefPtrNormals().get());
	geometry->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::Vec4Array> color = new osg::Vec4Array;
	color->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	geometry->setColorArray(color.get());
	geometry->setColorBinding(osg::Geometry::BIND_OVERALL);

	geometry->addPrimitiveSet(
		new osg::DrawArrays(osg::PrimitiveSet::TRIANGLES, 0, component->GetRefPtrTriangles()->size())
	);

	return geometry.release();
}

void Draw(vaar_data::DataModel& data_model) {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	
	vaar_data::Component* component = data_model.GetRoot();
	component = component->GetSubComponents()->at(0);

	geode->addDrawable(CreatGeometry(component));

	osgViewer::Viewer viwer;
	viwer.setSceneData(geode.get());
	viwer.run();
}

int main() {
	vaar_data::DataModel* data_model = new vaar_data::DataModel();
	vaar_file::FileReader* file_reader = new vaar_file::XMLReader;
	
	file_reader->Read("tutor.xml", *data_model);
	if (NULL != file_reader)
		delete file_reader;

	Draw(*data_model);

	if (NULL != data_model)
		delete data_model;
	
	return 0;
}