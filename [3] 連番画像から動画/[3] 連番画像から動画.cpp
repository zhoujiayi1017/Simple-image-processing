/*　動画再生　*/
/*　参考文献　OpenCVのVideoWriterを使って画像から動画を作る。
http://shibafu3.hatenablog.com/entry/2016/11/13/151118
*/

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat img;

	//動画作成に必要な情報
	int max_f = 345;
	int img_w = 352;
	int img_h = 352;
	double fps = 15.0;
	
	//動画作成の関数 true→RGB　false→モノクロ
	//fourcc tag 0x34363248/'H264' codec_id 001B
	VideoWriter writer("make_movie\\doraemon.avi", 
		VideoWriter::fourcc('D', 'I', 'V', '3'), fps, cv::Size(img_w, img_h), true);


	for (int i = 0; i < max_f; i++) {

		//1フレーム分取り出してimgに保持させる
		std::ostringstream oss;
		oss << std::setfill('0') << std::setw(3) << i;//三桁
		img = imread("movie_img\\pic_" + oss.str() + ".png");

		//現在のフレーム番号を表示
		std::cout << "フレーム番号 " << i << std::endl;

		//画像を表示
		imshow("Video", img);

		//動画に加える
		writer << img;

		// 表示のために100ms待つ
		waitKey(30);
	}

	
	return 0;
}

/*
C:\opencv\build\include

C:\opencv\build\x64\vc15\lib

opencv_world400.lib;%(AdditionalDependencies)
*/