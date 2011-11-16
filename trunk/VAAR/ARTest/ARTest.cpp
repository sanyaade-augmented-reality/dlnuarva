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
		// ���������
		aruco::CameraParameters camera_params;
		// ���̽����
		MarkerDetector marker_detector;
		// �������
		vector<Marker> markers;
		// ��ǳߴ�
		float marker_size = -1;

		// ��ȡ����ͼƬ
		cv::Mat in_image = cv::imread("in.jpg");
		// ��ȡ�������������CameraClibration����
		camera_params.readFromXMLFile("camera.yml");

		// ����ͼƬ�޸���������ĳߴ�
		camera_params.resize(in_image.size());

		// ���ñ�ǵĳߴ�
		//if (argc>=4) MarkerSize=atof(argv[3]);

		// ע�ᴰ��
		cv::namedWindow("in",1);

		// ��ͼƬ̽����
		marker_detector.detect(in_image, markers, camera_params, marker_size);
		
		// ��������Ϣ������
		for(unsigned int i = 0; i < markers.size(); i++){
			cout << markers[i] << endl;
			markers[i].draw(in_image, Scalar(0,0,255), 2);
		}

		// �ڱ���ϻ���3d����
		if (camera_params.isValid()) {
			for(unsigned int i = 0; i < markers.size(); i++){
				CvDrawingUtils::draw3dCube(in_image, markers[i], camera_params);
			}
		}

		// չʾ
		cv::imshow("in", in_image);
		cv::waitKey(0);

		// ���
		cv::imwrite("out.jpg", in_image);

	} catch(std::exception &ex) {
		std::cout << "Exception :" << ex.what() << std::endl;
	}

	return 0;
}