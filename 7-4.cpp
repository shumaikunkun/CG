#include "stdafx.h"

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include <stdio.h>

#define OUTPUT_FILENAME "parametric_surface.obj" // 出力ファイル名
#define PI 3.1415926535

#define NUM_U 50  // U方向の分割数
#define NUM_V 50  // V方向の分割数

double x[NUM_U + 1][NUM_V + 1]; // x 座標
double y[NUM_U + 1][NUM_V + 1]; // y 座標
double z[NUM_U + 1][NUM_V + 1]; // z 座標

								// 配列に座標値を設定する
void setCoordinates() {

	for (int i = 0; i < NUM_U + 1; i++) {
		for (int j = 0; j < NUM_V + 1; j++) {

			// u と v の値を 0.0 ～ 1.0 に正規化する
			double u = 1.0 / NUM_U * i;
			double v = 1.0 / NUM_V * j;

			// 座標値の設定 (平面)
			x[i][j] = u;
			y[i][j] = v;
			z[i][j] = 0;
		}
	}
}

// OBJ 形式でのファイルの出力
void exportOBJ() {
	FILE *fp;
	errno_t error;

	// 出力用ファイルを開く
	//---------------------------
	error = fopen_s(&fp, OUTPUT_FILENAME, "r");

	//ファイルを作成できなかった場合のエラー処理
	if (error !=0) {
		printf("Error: fopen\n");
		exit(0);
	}



	// 頂点情報の出力
	//---------------------------
	for (int i = 0; i < NUM_U + 1; i++) {
		for (int j = 0; j < NUM_V + 1; j++) {
			fprintf(fp, "v %f %f %f\n", x[i][j], y[i][j], z[i][j]);
		}
	}

	// 面情報の出力
	//---------------------------

	for (int i = 0; i < NUM_U; i++) {
		for (int j = 0; j < NUM_V; j++) {
			int lb_index = j + (NUM_U + 1)*i;// 左下の頂点番号番号の計算式
			int lt_index = j + (NUM_U + 1)*i + 1;// 左上の頂点番号番号の計算式
			int rb_index = j + (NUM_U + 1)*(i + 1);// 右下の頂点番号番号の計算式
			int rt_index = j + (NUM_U + 1)*(i + 1) + 1;// 右上の頂点番号番号の計算式


													   // 三角形を構成する頂点番号を出力（OBJ形式の場合はインデックスが1から始まる）
			fprintf(fp, "f %d %d %d\n", lb_index + 1, rt_index + 1, lt_index + 1);
			fprintf(fp, "f %d %d %d\n", lb_index + 1, rb_index + 1, rt_index + 1);
		}
	}

	// 出力用ファイルを閉じる
	//---------------------------
	fclose(fp);
}

int main(int argc, char** argv) {
	setCoordinates();
	exportOBJ();
	return 0;
}
