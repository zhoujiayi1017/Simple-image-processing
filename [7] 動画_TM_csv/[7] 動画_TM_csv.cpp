/*　動画再生　*/
/* 参考文献　C++版 OpenCVの基本
https://cvtech.cc/opencv/2/
*/

#include "pch.h"
#include <iostream>
#include <fstream>	//csv出力のライブラリ
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

	//テンプレートマッチングに必要な変数
	double MaxVal;
	Point max_pt;

	//動画をキャプチャ
	VideoCapture cap("sample\\3_sample_mov.mp4"); //Windowsの場合　パス中の¥は重ねて¥¥とする
	//VideoCapture cap("videos/sample.mp4"); //Macの場合

	//動画の最大フレーム数
	int max_frame = (int)cap.get(CAP_PROP_FRAME_COUNT);
	// 動画の高さ
	int img_h = (int)cap.get(CAP_PROP_FRAME_HEIGHT);
	// 動画の幅
	int img_w = (int)cap.get(CAP_PROP_FRAME_HEIGHT);
	// 動画のfps
	double fps = cap.get(CAP_PROP_FPS);

	//csv出力
	std::ofstream csv("csv_file\\ドラえもんの類似度.csv");



	for (int i = 0; i < max_frame; i++) {

		//1フレーム分取り出してimgに保持させる
		cap >> img;

		/* テンプレートマッチング　開始 */
		// テンプレートと，それに重なった画像領域とを比較
		matchTemplate(img, tmp, rlt, TM_CCORR_NORMED);

		//minMaxLoc(Mat型の出力結果, 類似度が一番低い値, 類似度が一番高い値, 低い座標, 高い座標)
		minMaxLoc(rlt, NULL, &MaxVal, NULL, &max_pt);

		// 入力画像に結果を反映
		rectangle(img, max_pt, Point(max_pt.x + tmp.cols, max_pt.y + tmp.rows), Scalar(0, 0, 255), 2, 8, 0);

		// 画像を表示
		imshow("Video", img);
		/* テンプレートマッチング　終了 */


		//現在のフレーム番号を表示
		std::cout << "フレーム番号 " << i << std::endl;

		//現在の類似度を出力
		std::cout << "類似度 " << MaxVal << std::endl;

		//値（類似度）をcsvファイルに出力
		csv << i << "," << MaxVal << std::endl;

		// 表示のために100ms待つ
		waitKey(30);
	}

	//動画情報の出力
	std::cout << "フレーム番号 " << max_frame - 1 << std::endl;//345
	std::cout << "動画の高さ " << img_h << std::endl; //352
	std::cout << "動画の幅 " << img_w << std::endl;// 352
	std::cout << "動画のfps " << fps << std::endl;// 15

	return 0;
}

/*
C:\opencv\build\include

C:\opencv\build\x64\vc15\lib

opencv_world400.lib;%(AdditionalDependencies)
*/