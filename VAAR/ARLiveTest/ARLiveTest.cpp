#include <iostream>
#include <fstream>
#include <sstream>
#include "../AR/aruco.h"

cv::VideoCapture video_capture;
cv::Mat input_image, input_image_copy;
aruco::MarkerDetector marker_dector;
aruco::CameraParameters camera_params;
vector<aruco::Marker> markers;
pair<double,double> average_time(0,0);
float marker_size = 0.111;
double threshold_param1, threshold_param2;
int i_threshold_param1, i_threshold_param2;

void cvTackBarEvents(int pos,void*) {
	if (i_threshold_param1 < 3) 
		i_threshold_param1 = 3;
	if (i_threshold_param1 % 2 != 1) 
		i_threshold_param1++;
	if (i_threshold_param2 < 1) 
		i_threshold_param2 = 1;

	threshold_param1 = i_threshold_param1;
	threshold_param2 = i_threshold_param2;
	marker_dector.setThresholdParams(threshold_param1, threshold_param2);

	//recompute
	marker_dector.detect(input_image, markers, camera_params);
	input_image.copyTo(input_image_copy);

	for(unsigned int i=0; i < markers.size(); i++)
		markers[i].draw(input_image, Scalar(0, 0, 255), 2);

	//draw a 3d cube in each marker if there is 3d info
	if (camera_params.isValid())
		for(unsigned int i=0; i < markers.size(); i++)
			aruco::CvDrawingUtils::draw3dCube(input_image_copy, markers[i], camera_params);

	cv::imshow("in", input_image_copy);
	cv::imshow("thres", marker_dector.getThresholdedImage());
}

int main() {
	
	

	// 打开摄像头
	video_capture.open(0);
	if (!video_capture.isOpened()){
		std::cerr << "Could not open video" << endl;
		return -1;
	}

	// 获取第一张图像，用于这设置参数
	video_capture >> input_image;

	// 读取摄像机参数
	camera_params.readFromXMLFile("camera.yml");
	camera_params.resize(input_image.size());

	// 注册窗口
	cv::namedWindow("thres",1);
	cv::namedWindow("in",1);

	marker_dector.getThresholdParams(threshold_param1, threshold_param2);
	i_threshold_param1 = threshold_param1;
	i_threshold_param2 = threshold_param2;

	cv::createTrackbar("ThresParam1", "in",&i_threshold_param1, 13, cvTackBarEvents);
	cv::createTrackbar("ThresParam2", "in",&i_threshold_param2, 13, cvTackBarEvents);

	char key=0;
	int index=0;

	//capture until press ESC or until the end of the video
	while( key!=27 && video_capture.grab())
	{
		//copy image
		video_capture.retrieve(input_image);
		
		//number of images captured
		index++; 

		//for checking the speed
		double tick = (double)cv::getTickCount();
		//Detection of markers in the image passed
		marker_dector.detect(input_image, markers, camera_params, marker_size);
		//chekc the speed by calculating the mean speed of all iterations
		average_time.first += ((double)cv::getTickCount() - tick) / cv::getTickFrequency();
		average_time.second++;
		std::cout << "Time detection=" << 1000 * average_time.first / average_time.second << " milliseconds" << endl;

		//print marker info and draw the markers in image
		input_image.copyTo(input_image_copy);
		for(unsigned int i = 0; i < markers.size(); i++){
			std::cout << markers[i] << std::endl;
			markers[i].draw(input_image, Scalar(0, 0, 255), 2);
		}

		//draw a 3d cube in each marker if there is 3d info
		if ( camera_params.isValid())
			for(unsigned int i = 0; i < markers.size(); i++){
				aruco::CvDrawingUtils::draw3dCube(input_image, markers[i], camera_params);
				aruco::CvDrawingUtils::draw3dAxis(input_image, markers[i], camera_params);
			}

			//DONE! Easy, right?
			cout << endl << endl << endl;
			//show input with augmented information and  the thresholded image
			cv::imshow("in", input_image);
			cv::imshow("thres", marker_dector.getThresholdedImage());

			key=cv::waitKey(0);//wait for key to be pressed
	}
	return 0;
}