#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;

class Template_class {
public:

	Mat rlt;//�o�͌��ʉ摜

	double MaxVal;//�ގ��x
	Point max_pt;//�ł��ގ����Ă�����W

	//���͉摜�A�e���v�摜�A�t���[���ԍ�
	void tmp_(Mat img, Mat tmp, int i);


};


void Template_class::tmp_(Mat img, Mat tmp, int i) {
	/* �e���v���[�g�}�b�`���O�@�J�n */
	// �e���v���[�g�ƁC����ɏd�Ȃ����摜�̈�Ƃ��r
	matchTemplate(img, tmp, rlt, TM_CCORR_NORMED);

	//minMaxLoc(Mat�^�̏o�͌���, �ގ��x����ԒႢ�l, �ގ��x����ԍ����l, �Ⴂ���W, �������W)
	minMaxLoc(rlt, NULL, &MaxVal, NULL, &max_pt);

	// ���͉摜�Ɍ��ʂ𔽉f
	rectangle(img, max_pt, Point(max_pt.x + tmp.cols, max_pt.y + tmp.rows), Scalar(0, 0, 255), 2, 8, 0);

	// �摜��\��
	imshow("Video", img);
	/* �e���v���[�g�}�b�`���O�@�I�� */


	//���݂̃t���[���ԍ���\��
	std::cout << "�t���[���ԍ� " << i << std::endl;

	//���݂̗ގ��x���o��
	std::cout << "�ގ��x " << MaxVal << std::endl;

	// �\���̂��߂�100ms�҂�
	waitKey(30);

	//return MaxVal;
}