#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../AR/aruco.h"
#include "../AR/cvdrawingutils.h"

using namespace cv;
using namespace aruco;

int main(int argc,char **argv) {
	try {
		aruco::CameraParameters camera_params;
		MarkerDetector marker_detector;
		vector<Marker> markers;
		float marker_size = -1;

		cv::Mat in_image = cv::imread("in.jpg");
		camera_params.readFromXMLFile("camera.yml");

		//resizes the parameters to fit the size of the input image
		camera_params.resize(in_image.size());

		//if (argc>=4) MarkerSize=atof(argv[3]);
		cv::namedWindow("in",1);
		marker_detector.detect(in_image, markers, camera_params, marker_size);
		//for each marker, draw info and its boundaries in the image
		for(unsigned int i=0; i < markers.size(); i++){
			cout << markers[i] << endl;
			markers[i].draw(in_image, Scalar(0,0,255), 2);
		}

		//draw a 3d cube in each marker if there is 3d info
		if (camera_params.isValid()) {
			for(unsigned int i=0; i < markers.size(); i++){
				CvDrawingUtils::draw3dCube(in_image, markers[i], camera_params);
			}
		}

		//show input with augmented information
		cv::imshow("in", in_image);
		cv::waitKey(0);//wait for key to be pressed
		cv::imwrite("out.jpg", in_image);

	} catch(std::exception &ex) {
		std::cout << "Exception :" << ex.what() << std::endl;
	}

}