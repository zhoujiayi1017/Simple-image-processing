#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;

class Template_class {
public:

	Mat rlt;//出力結果画像

	double MaxVal;//類似度
	Point max_pt;//最も類似している座標

	//入力画像、テンプ画像、フレーム番号
	void tmp_(Mat img, Mat tmp, int i);


};


void Template_class::tmp_(Mat img, Mat tmp, int i) {
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

	// 表示のために100ms待つ
	waitKey(30);

	//return MaxVal;
}