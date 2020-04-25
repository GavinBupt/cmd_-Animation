#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>							
#include <opencv2\imgcodecs.hpp>
#include <opencv2\video.hpp>
#include <opencv2\highgui.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <Windows.h>

using namespace std;
using namespace cv;

//char char_list[] = { '#','&' ,'$','*','o','!',';',' ' };
//char* char_list = (char*)" .'iltoenmTFENM";
//char* char_list = (char*)" .'TsinghuaUniversity";
//char* char_list = (char*)" .'清华大学生日快乐";
string char_list = "  .'singhuaT";
string char_list2 = "华清";
//string char_list3 = "清";
//char char_list[] = { ' ','0' ,'1' };
int main()
{
	//==========制作字符画============
	cout.imbue(locale("chs"));
	Mat m_image = imread("C:/Users/Gavinous/Desktop/cmd_-Animation-master/清华大学.jpg");
	vector<int> result;
	// C:/Users/Administrator/Desktop/第一版.mp4
	int len = char_list.length() + char_list2.length()/2;
	int qujian = ceil(float(255) / float(len));
	Mat frame, frame_resize, m_gray;
	cout << char_list << char_list2[0] << char_list2[1] << char_list << char_list2[2] << char_list2[3]<< endl;
	cout << qujian << endl;
	//getchar();
	//return 0;
	if (!m_image.empty()) {
		//imshow("hello opencv", m_image);
		//resize(m_image, m_image, Size(325, 90));
		//resize(m_image, m_image, Size(300, 80));
		resize(m_image, frame_resize, Size(538, 200)); //字符5
		//resize(m_image, frame_resize, Size(448, 160)); 字符6
		//resize(m_image, frame_resize, Size(336, 120)); 字符8
		cvtColor(frame_resize, m_gray, CV_BGR2GRAY);
		string buff = "";

		for (int j = 0; j < m_gray.rows; ++j) {
			for (int i = 0; i < m_gray.cols; ++i) {
				int pdata = m_gray.ptr<uchar>(j)[i];
				if (pdata == 255)
				{
					result.push_back(len - 1);
					i++;
					//buff += char_list2[char_list2.length() - 1];
				}//buff += char_list[14];	
				else
					//buff += char_list[pdata / 17];
				{	
					int pos = pdata / qujian;
					result.push_back(pos);	
					if (pos > char_list.length() - 1)
						i++;
				}
			}
			result.push_back(len);
			//buff += "\n";
		}
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i] == len)
			{
				cout << "\n";
			}
			else {
				int pos = result[i];
				if (pos > char_list.length() - 1)
				{
					//printf("%c", char_list2[pos - char_list.length()]);
					cout << char_list2[(pos - char_list.length())*2] << char_list2[(pos - char_list.length()) * 2 + 1 ];
				}
				else {
					printf("%c", char_list[pos]);
					//cout<<char_list[pos];
				}
			}
		}
			
		//cout << buff.length() << endl;
		//cout << buff << endl;
		//getchar();
		//HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		//COORD pos;
		//pos.X = 0;
		//pos.Y = 0;
		//SetConsoleCursorPosition(hConsoleOutput, pos);
		//cout << buff;
		//system("cls");
		/*ofstream charfile("lena_char.txt");
		if (charfile) {
		charfile << buff;
		charfile.close();
		}*/
	}
	
	waitKey(0);
	system("pause");
	return 0;
}