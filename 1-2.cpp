#include <GL/glut.h> // ライブラリ用ヘッダファイルの読み込み // 表示部分をこの関数で記入
#include <stdio.h>
#include <string.h>
#include <math.h>

int j = 0; //arrがどこまで使われているか(使われている配列のサイズ)を格納
double arr[1000][2], copy[1000][2];  //点の座標一覧を順番に格納する配列とコピー用の配列

void display(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0); // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT); // 画面消去
	glColor3d(0.0, 0.0, 1.0); // 色指定(R,G,B)で0～1まで
	glBegin(GL_TRIANGLES); // 描画するものを指定
	for (int i = 0; i < j; i += 3) {
		glVertex2d(arr[i][0], arr[i][1]);
		glVertex2d(arr[i+1][0], arr[i+1][1]);
		glVertex2d(arr[i+2][0], arr[i+2][1]);
	}	   // 頂点位置の指定
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


	for (int h = 0; h < 5; h++) {
		j = 0;
		for (int i = 0; i < pow(3, h + 1); i += 3) {
			copy[j][0] = arr[i][0];
			copy[j][1] = arr[i][1];
			j++;
			copy[j][0] = (arr[i][0] + arr[i + 1][0]) / 2;
			copy[j][1] = (arr[i][1] + arr[i + 1][1]) / 2;
			j++;
			copy[j][0] = (arr[i][0] + arr[i + 2][0]) / 2;
			copy[j][1] = (arr[i][1] + arr[i + 2][1]) / 2;
			j++;
			copy[j][0] = (arr[i][0] + arr[i + 1][0]) / 2;
			copy[j][1] = (arr[i][1] + arr[i + 1][1]) / 2;
			j++;
			copy[j][0] = arr[i + 1][0];
			copy[j][1] = arr[i + 1][1];
			j++;
			copy[j][0] = (arr[i + 1][0] + arr[i + 2][0]) / 2;
			copy[j][1] = (arr[i + 1][1] + arr[i + 2][1]) / 2;
			j++;
			copy[j][0] = (arr[i][0] + arr[i + 2][0]) / 2;
			copy[j][1] = (arr[i][1] + arr[i + 2][1]) / 2;
			j++;
			copy[j][0] = (arr[i + 1][0] + arr[i + 2][0]) / 2;
			copy[j][1] = (arr[i + 1][1] + arr[i + 2][1]) / 2;
			j++;
			copy[j][0] = arr[i + 2][0];
			copy[j][1] = arr[i + 2][1];
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
