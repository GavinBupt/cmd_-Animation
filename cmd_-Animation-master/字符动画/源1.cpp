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
#include <mmsystem.h>
#include <atlstr.h>
#include <Vfw.h>

#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"Vfw32.lib")

using namespace std;
using namespace cv;

//char char_list[] = { '#','&' ,'$','*','o','!',';',' ' };
char* char_list = (char*)" .'iltoenmTFENM";
bool quit = false;
bool pause = false;

int main()
{
	//=========ÖÆ×÷×Ö·û¶¯»­============

	HWND m_hwndMCI = NULL;
	HWND m_hWnd = NULL;
	if (m_hwndMCI != NULL)
	{
		MCIWndDestroy(m_hwndMCI);
	}
	int type = 0;
	CString filename = "nomico - Bad Apple!!.mp3";
	m_hwndMCI = MCIWndCreate(m_hWnd, GetModuleHandle(0), type, filename);
	MCIWndPlay(m_hwndMCI);

	VideoCapture cap;
	cap.open("bad apple.mp4");
	if (!cap.isOpened()) {
		cout << "can't open file" << endl;
		return -1;
	}
	Mat frame, frame_resize, frame_gray;
	while (!quit) {
		cap >> frame;
		if (frame.empty()) break;
		resize(frame, frame_resize, Size(80, 24));
		cvtColor(frame_resize, frame_gray, CV_BGR2GRAY);
		string buff = "";

		for (int j = 0; j < frame_gray.rows; ++j) {
			for (int i = 0; i < frame_gray.cols; ++i) {
				int pdata = frame_gray.ptr<uchar>(j)[i];
				if (pdata == 255)
					buff += char_list[14];
				else
					buff += char_list[pdata / 17];
			}
			buff += "\n";
		}

		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = 0;
		pos.Y = 0;
		SetConsoleCursorPosition(hConsoleOutput, pos);
		cout << buff;
		cout << "frame:" << cap.get(CV_CAP_PROP_POS_FRAMES) << endl;

		imshow("badapple", frame);
		char key = waitKey(5);
		switch (key)
		{
		case 'q':quit = !quit; break;
		case 'p':pause = !pause; break;
		default:
			break;
		}
		if (pause) {
			waitKey();
			pause = !pause;
		}
	}

	return 0;
}