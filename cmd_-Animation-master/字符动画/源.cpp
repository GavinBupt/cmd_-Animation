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
	// C:/Users/Administrator/Desktop/第一版.mp4
	cap.open("G:/吉他换弦/提取/第一版.mp4");
	if (!cap.isOpened()) {
		cout << "can't open file" << endl;
		return -1;
	}
	Mat m_image ,frame, frame_resize, m_gray;
	while (true) {
		cap >> m_image;
		if (!m_image.empty()) {
			//imshow("hello opencv", m_image);
			//resize(m_image, m_image, Size(325, 90));
			//resize(m_image, m_image, Size(300, 80));
			if (frame.empty()) break;
			resize(frame, frame_resize, Size(80, 24));
			cvtColor(frame_resize, m_gray, CV_BGR2GRAY);
			string buff = "";

			for (int j = 0; j < m_gray.rows; ++j) {
				for (int i = 0; i < m_gray.cols; ++i) {
					int pdata = m_gray.ptr<uchar>(j)[i];
					if (pdata == 255)
						buff += char_list[14];
					else
						buff += char_list[pdata / 17];
				}
				buff += "\n";
			}
			
			//getchar();
			HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD pos;
			pos.X = 0;
			pos.Y = 0;
			SetConsoleCursorPosition(hConsoleOutput, pos);
			cout << buff;
			system("cls");
			/*ofstream charfile("lena_char.txt");
			if (charfile) {
			charfile << buff;
			charfile.close();
			}*/
		}
		else {
			break;
		}
	}
	waitKey(0);
	system("pause");
	return 0;
}
