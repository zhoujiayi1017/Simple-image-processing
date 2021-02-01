// [2] 画像_TM.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;


int main()
{
	//Mat型（行列）
	Mat img;//入力画像
	Mat tmp;//テンプレート画像
	Mat rlt;//出力結果画像

	//string型　文字列
	//入力画像の場所
	std::string img_path = "sample\\1_sample_img.png";
	//テンプレート画像の場所
	std::string tmp_path = "sample\\2_sample_tmp.png";

	//入力画像
	img = imread(img_path, 1);
	//テンプレート画像
	tmp = imread(tmp_path, 1);
	//出力結果画像
	//rlt = img.clone();
	imshow("Video_1", img);
	imshow("Video_2", tmp);

	// テンプレートと，それに重なった画像領域とを比較
	matchTemplate(img, tmp, rlt, TM_CCORR_NORMED);
	//imshow("Video_3", rlt);


	// 配列全体あるいは部分配列に対する，大域的最小値
	double MaxVal;
	Point max_pt;
	//minMaxLoc(Mat型の出力結果, 類似度が一番低い値, 類似度が一番高い値, 低い座標, 高い座標)
	minMaxLoc(rlt, NULL, &MaxVal, NULL, &max_pt);
	std::cout << max_pt << std::endl;

	//double mean_x = (max_pt.x + max_pt.x + tmp.cols) / 2;
	rectangle(img, max_pt, Point(max_pt.x + tmp.cols, max_pt.y + tmp.rows), Scalar(0, 0, 255), 2, 8, 0);
	imshow("Video_3", img);
	waitKey(0); // 表示のために1ms待つ

	

}

/*
C:\opencv\build\include

C:\opencv\build\x64\vc15\lib

opencv_world400.lib;%(AdditionalDependencies)
*/