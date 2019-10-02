#include <GL/glut.h> // ライブラリ用ヘッダファイルの読み込み // 表示部分をこの関数で記入
#include <stdio.h>
#include <string.h>
#include <math.h>

double a1, b1, a2, b2, a3, b3;  //角を形成する3点を格納する変数
int j = 0; //arrがどこまで使われているか(使われている配列のサイズ)を格納
double arr[1000][2], copy[1000][2];  //点の座標一覧を順番に格納する配列とコピー用の配列

void fun1(double x1, double y1, double x2, double y2) {  //三等分する2点を求める関数
	a1 = (2.0 * x1 + x2) / 3.0;
	b1 = (2.0 * y1 + y2) / 3.0;
	a3 = (x1 + 2.0 * x2) / 3.0;
	b3 = (y1 + 2.0 * y2) / 3.0;
}

void fun2(double x1, double y1, double x2, double y2) {  //三角形の頂点を求める関数
	a2 = 1.0 / 2.0 * (x2 - x1) - sqrt(3.0) / 2.0 * (y2 - y1) + x1;
	b2 = sqrt(3.0) / 2.0 * (x2 - x1) + 1.0 / 2.0 * (y2 - y1) + y1;
}

void display(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0); // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT); // 画面消去
	glColor3d(0.0, 0.0, 1.0); // 色指定(R,G,B)で0～1まで
	glBegin(GL_LINE_LOOP); // 描画するものを指定
	for (int i = 0; i < j; i++) glVertex2d(arr[i][0], arr[i][1]); // 頂点位置の指定
	glEnd();
	glFlush(); // 画面出力
} // メインプログラム

int main(int argc, char *argv[]) {
	//正三角形の座標の初期値
	arr[0][0] = -0.5;
	arr[0][1] = 0.0;
	arr[1][0] = 0.5;
	arr[1][1] = 0.0;
	arr[2][0] = 0.0;
	arr[2][1] = -sqrt(3.0) / 2.0;

	for (int h = 0; h < 4; h++) {
		j = 0;
		for (int i = 0; i < 3 * pow(4, h); i++) {
			if (i < 3 * pow(4, h) - 1) {
				fun1(arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
			}
			else {  //最後は配列の終端と始端を格納して1周させる
				fun1(arr[i][0], arr[i][1], arr[0][0], arr[0][1]);
			}
			fun2(a1, b1, a3, b3);
			copy[j][0] = arr[i][0];
			copy[j][1] = arr[i][1];
			j++;
			copy[j][0] = a1;
			copy[j][1] = b1;
			j++;
			copy[j][0] = a2;
			copy[j][1] = b2;
			j++;
			copy[j][0] = a3;
			copy[j][1] = b3;
			j++;
		}

		for (int k = 0; k < j; k++) {  //コピー配列にあるものを本番の配列にコピーする
			arr[k][0] = copy[k][0];
			arr[k][1] = copy[k][1];
		}
	}

	for (int k = 0; k < j; k++) {  //座標の表示
		printf("%lf %lf\n", arr[k][0], arr[k][1]);
	}

	glutInit(&argc, argv); // ライブラリの初期化
	glutInitWindowSize(400, 400); // ウィンドウサイズを指定
	glutCreateWindow(argv[0]); // ウィンドウを作成
	glutDisplayFunc(display); // 表示関数を指定
	glutMainLoop(); // イベント待ち
	return 0;
}
