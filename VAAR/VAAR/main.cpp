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
#include "../AR/aruco.h"

bool g_switch_color = false;

cv::VideoCapture video_capture;
cv::Mat input_image;
cv::Size original_image_size(640, 480), display_image_size(1280, 1024);
double projection_matrix[16], model_view_matrix[16];
aruco::MarkerDetector marker_dector;
aruco::CameraParameters camera_params;
vector<aruco::Marker> markers;
float marker_size = 0.111;
double threshold_param1, threshold_param2;


void Invert(double matrix[16]) {
	double temp;
	int index_1, index_2;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i == j) continue;
			index_1 = i * 4 + j;
			index_2 = j * 4 + i;
			temp = matrix[index_1];
			matrix[index_1] = matrix[index_2];
			matrix[index_2] = temp;
		}
	}
}

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

class ProjectionMatrixUpdateCallback : public osg::NodeCallback {
public:
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) {

		osg::Projection* projection = dynamic_cast<osg::Projection*>(node);
		if (projection) {
			video_capture.retrieve(input_image);
			marker_dector.detect(input_image, markers, camera_params, marker_size);
			marker_dector.glGetProjectionMatrix(
				camera_params, original_image_size, display_image_size, projection_matrix, 2, 800, true);
			Invert(projection_matrix);
			projection->setMatrix(osg::Matrix(projection_matrix));
		}
		traverse(node, nv);
	}
};

class ModelViewMatrixUpdateCallback : public osg::NodeCallback {
public:
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) {

		osg::MatrixTransform* transform = dynamic_cast<osg::MatrixTransform*>(node);
		if (transform && markers.size() > 0) {
			markers[0].glGetModelViewMatrix(model_view_matrix);
			Invert(model_view_matrix);
			transform->setMatrix(osg::Matrix(model_view_matrix));
		}
		traverse(node, nv);
	}
};

osg::Geometry* CreatGeometry(vaar_data::Component* component) {
	osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	
	geometry->setVertexArray(component->GetRefPtrTriangles().get());
	
	geometry->setNormalArray(component->GetRefPtrNormals().get());
	geometry->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::Vec4Array> color = new osg::Vec4Array;

	// 变换颜色
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

void InitializeAR() {
	// 打开摄像头
	video_capture.open(0);
	if (!video_capture.isOpened()){
		std::cerr << "Could not open video" << endl;
		return;
	}

	// 获取第一张图像，用于这设置参数
	video_capture >> input_image;

	// 读取摄像机参数
	camera_params.readFromXMLFile("camera.yml");
	camera_params.resize(input_image.size());
}

void ARDraw(vaar_data::DataModel& data_model) {
	osg::ref_ptr<osg::Geode> model = new osg::Geode;

	vaar_data::Component* component = data_model.GetRoot();
	model->addDrawable(CreatGeometry(component->GetSubComponents()->at(0)));

	osg::ref_ptr<osg::Group> root = new osg::Group;

	osg::ref_ptr<osg::MatrixTransform> model_view = new osg::MatrixTransform;
	model_view->addChild(model);
	model_view->setUpdateCallback(new ModelViewMatrixUpdateCallback);

	osg::ref_ptr<osg::Projection> projection = new osg::Projection;
	projection->addChild(model_view);
	projection->setUpdateCallback(new ProjectionMatrixUpdateCallback);

	root->addChild(projection);

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

	//Draw(*data_model);

	InitializeAR();
	ARDraw(*data_model);

	if (NULL != data_model)
		delete data_model;
	
	return 0;
}