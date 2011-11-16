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
		// 摄像机参数
		aruco::CameraParameters camera_params;
		// 标记探测类
		MarkerDetector marker_detector;
		// 标记数组
		vector<Marker> markers;
		// 标记尺寸
		float marker_size = -1;

		// 读取测试图片
		cv::Mat in_image = cv::imread("in.jpg");
		// 读取摄像机参数，由CameraClibration生成
		camera_params.readFromXMLFile("camera.yml");

		// 根据图片修改相机参数的尺寸
		camera_params.resize(in_image.size());

		// 设置标记的尺寸
		//if (argc>=4) MarkerSize=atof(argv[3]);

		// 注册窗口
		cv::namedWindow("in",1);

		// 从图片探测标记
		marker_detector.detect(in_image, markers, camera_params, marker_size);
		
		// 输出标记信息并绘制
		for(unsigned int i = 0; i < markers.size(); i++){
			cout << markers[i] << endl;
			markers[i].draw(in_image, Scalar(0,0,255), 2);
		}

		// 在标记上绘制3d方块
		if (camera_params.isValid()) {
			for(unsigned int i = 0; i < markers.size(); i++){
				CvDrawingUtils::draw3dCube(in_image, markers[i], camera_params);
			}
		}

		// 展示
		cv::imshow("in", in_image);
		cv::waitKey(0);

		// 输出
		cv::imwrite("out.jpg", in_image);

	} catch(std::exception &ex) {
		std::cout << "Exception :" << ex.what() << std::endl;
	}

	return 0;
}