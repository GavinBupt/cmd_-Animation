#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>							
#include <opencv2\imgcodecs.hpp>
#include <opencv2\video.hpp>
#include <opencv2\highgui.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <Windows.h>

using namespace std;
using namespace cv;

//char char_list[] = { '#','&' ,'$','*','o','!',';',' ' };
char* char_list = (char*)" .'iltoenmTFENM";
//char char_list[] = { ' ','0' ,'1' };
int main()
{
	//==========制作字符画============

	//Mat m_image = imread("C:/Users/Administrator/Desktop/无敌.JPG");
	VideoCapture cap;
	cap.open("G:/吉他换弦/提取/吉他1.mp4");
	
	if (!cap.isOpened()) {
		cout << "can't open file" << endl;
		return -1;
	}
	double rate = 25.0;//视频的帧率
	Size videoSize(1920,1080);
	VideoWriter writer("G:/guitar.avi", CV_FOURCC('M', 'J', 'P', 'G'), rate, videoSize);
	Mat m_image, frame, frame_resize, m_gray;
	int num = 1;
	while (true) {
		cap >> m_image;
		if (!m_image.empty()) {
			Vec3b pixel[9][9];
			int cal = 0;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					pixel[i][j] = m_image.at<uchar>(1055 + i, 55 + j);
					if (int(pixel[i][j][0]) == 11)
						cal++;
					//cout << int(pixel[i][j][0]) << " ";
				}
				//cout << endl;
			}
			//cout << "————————————————————————" << endl;
				
			
			//cout << int(pixel[0]) << " " << int(pixel[1]) << " " << int(pixel[2]) << endl;
			//if (num >= 3000)
			//	break;
			//if (int(pixel[0]) != 11 && int(pixel[0]) != 12)
			if (cal < 40)
			{
				writer << m_image;
				//imshow("hello opencv", m_image);
				//waitKey(10);
				cout << num << endl;
				num++;
			}
			
		}
		else {
			break;
		}
	}
	cout << "写完啦！" << endl;
	waitKey(0);
	system("pause");
	return 0;
}
