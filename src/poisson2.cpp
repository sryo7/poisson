// poisson2.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>


using namespace cv;

int main()
{
	// 画像の読み込み
	Mat src = imread("C:/Users/僚/Pictures/opencv/arimura.png");
	Mat background = imread("C:/Users/僚/Pictures/opencv/grasslandscape.png");
	Mat mask = imread("C:/Users/僚/Pictures/opencv/arimuramask2.png");

	for (int y = 0; y < src.rows; y++) {
		// ポインタの取得
		Vec3b* ptr_src = src.ptr<Vec3b>(y);
		Vec3b* ptr_background = background.ptr<Vec3b>(y);
		Vec3b* ptr_mask = mask.ptr<Vec3b>(y);

		for (int x = 0; x < src.cols; x++) {
			// 値の取得
			//Vec3b bgr = ptr_src[x];

			// 値の設定
			if (ptr_mask[x] == Vec3b(0, 0, 0)) {
				ptr_src[x] = ptr_background[x];
			}
		}
	}
	// 結果としてmask白色の箇所はsrc、黒色の箇所はbackgroundの画素が表示される
	
	namedWindow("result", 1);
	imshow("result", src);
	waitKey(0);

    return 0;
}

