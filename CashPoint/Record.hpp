#include <opencv2/opencv.hpp>
#include <Windows.h>
#include <iostream>
#include <stdio.h>

#include "DesktopDimen.hpp"

using namespace cv;
using namespace std;

namespace Record
{
	class Camera
	{
	public:
		void TakePhoto(string filename)
		{
			Mat Access = LoadCamera();
			imwrite(filename, Access);
		}
		void LoadLive()
		{
			VideoCapture cam(0);

			Mat Frame;

			if (!cam.isOpened())
			{
				cout << "Cannot access camera";
			}
			else
			{
				while (true)
				{
					cam >> Frame;

					imshow("Webcam", Frame);
					waitKey(1);
					
				}
				destroyAllWindows();
				cam.release();
			}
		}
		void LoadLive2Video(const char filename[])
		{

			VideoCapture cam(0);

			if (!cam.isOpened())
			{
				cout << "cannot access camera\n";
			}
			
			Mat Frame;

			int Width = cam.get(CAP_PROP_FRAME_WIDTH);
			int Height = cam.get(CAP_PROP_FRAME_HEIGHT);

			VideoWriter Writer(filename, VideoWriter::fourcc('M', 'J', 'P', 'G'), 32, Size(Width, Height));

			while (cam.read(Frame) && GetKeyState(VK_ESCAPE) == 0)
			{
				imshow("CCTV", Frame);
				Writer.write(Frame);
				waitKey(1);
			}
			destroyAllWindows();
			Writer.release();
			cam.release();
			
		}

	private:
		Mat LoadCamera()
		{
			VideoCapture cap(0);

			Mat Frame;

			if (!cap.isOpened())
			{
				cout << "Cam Not Found\n";
				return Frame;
			}
			else
			{
				cap >> Frame;
				cap.release();
			}
			return Frame;
		}
	};
}