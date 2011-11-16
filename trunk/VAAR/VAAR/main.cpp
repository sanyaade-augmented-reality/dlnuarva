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

bool g_switch_color = false;

class ChangePositionCallback : public osg::NodeCallback {
public:
	ChangePositionCallback() : x_(0.0) {}
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) {
		osg::MatrixTransform* transform = dynamic_cast<osg::MatrixTransform*>(node);

		if (transform) {
			transform->setMatrix(osg::Matrix::translate(x_, 0, 0));
			x_ += 10;
			if (x_ > 1000.0)
				x_ = 0.0;
		}
		traverse(node, nv);
	}
private:
	float x_;
};

osg::Geometry* CreatGeometry(vaar_data::Component* component) {
	osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	
	geometry->setVertexArray(component->GetRefPtrTriangles().get());
	
	geometry->setNormalArray(component->GetRefPtrNormals().get());
	geometry->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::Vec4Array> color = new osg::Vec4Array;

	// ±ä»»ÑÕÉ«
	if (g_switch_color) {
		color->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
		g_switch_color = !g_switch_color;
	} else {
		color->push_back(osg::Vec4(0.0f, 0.0f, 0.8f, 1.0f));
		g_switch_color = !g_switch_color;
	}
	
	geometry->setColorArray(color.get());
	geometry->setColorBinding(osg::Geometry::BIND_OVERALL);

	geometry->addPrimitiveSet(
		new osg::DrawArrays(osg::PrimitiveSet::TRIANGLES, 0, component->GetRefPtrTriangles()->size())
	);

	return geometry.release();
}

void Draw(vaar_data::DataModel& data_model) {
	osg::ref_ptr<osg::Geode> geode_1 = new osg::Geode;
	osg::ref_ptr<osg::Geode> geode_2 = new osg::Geode;
	
	vaar_data::Component* component = data_model.GetRoot();
	geode_1->addDrawable(CreatGeometry(component->GetSubComponents()->at(0)));
	geode_2->addDrawable(CreatGeometry(component->GetSubComponents()->at(1)));

	osg::ref_ptr<osg::Group> root = new osg::Group;

	osg::ref_ptr<osg::MatrixTransform> transform_1 = new osg::MatrixTransform;
	transform_1->setMatrix(osg::Matrix::translate(200, 0, 0));
	transform_1->addChild(geode_1);
	transform_1->setUpdateCallback(new ChangePositionCallback);

	osg::ref_ptr<osg::MatrixTransform> transform_2 = new osg::MatrixTransform;
	transform_2->setMatrix(osg::Matrix::translate(0, 0, 0));
	transform_2->addChild(geode_2);

	root->addChild(transform_1);
	root->addChild(transform_2);

	osgViewer::Viewer viwer;
	viwer.setSceneData(root.get());
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