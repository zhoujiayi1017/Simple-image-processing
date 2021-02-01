/* 入力画像とテンプレート画像の二つを出力する */
/* 参考サイト　OpenCV(C++)の画像処理メモ
https://qiita.com/yoyoyo_/items/aada199371f6802bb887 
   参考サイト　OpenCV/C++で画像処理入門 vol.1 〜画像を表示してみよう〜
https://qiita.com/yoyoyo_/items/aada199371f6802bb887 */

//環境変数パスを記述する

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{

	//Mat型（行列）
	cv::Mat img;//入力画像
	cv::Mat tmp;//テンプレート画像

	//string型　文字列
	//入力画像の場所
	std::string img_path = "sample\\1_sample_img.png";
	//テンプレート画像の場所
	std::string tmp_path = "sample\\2_sample_tmp.png";

	//入力画像
	//RGB読み込み
	img = cv::imread(img_path, 1);	
	//グレースケール読み込み
	//img = cv::imread(img_path,0);	

	//テンプレート画像
	//RGB読み込み
	tmp = cv::imread(tmp_path, 1);


	//入力画像　タイトル名、変数
	cv::imshow("入力画像", img);

	//テンプレート画像
	cv::imshow("テンプレート画像", tmp);

	//無限時間待つ
	cv::waitKey(0);

	return 0;
}

/*
C++ 

C:\opencv\build\include

C:\opencv\build\x64\vc15\lib

opencv_world400.lib;%(AdditionalDependencies)

*/

