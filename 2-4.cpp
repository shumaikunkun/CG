#include <math.h>
#include <GL/glut.h> // ライブラリ用ヘッダファイルの読み込み

// 定数πの定義
#ifndef M_PI
#define M_PI 3.14159265358979
#endif

// ディスプレイリストの学習
// 星を描画する描画命令一式を、ディスプレイリストとして作成しておき
// 必要な時に、その命令を呼び出す

#define ID_DRAW_BALL 1 //  glNewList 関数で使用する識別ID。値は何でも構わない

int rotateAngle; // 回転角度を記録しておく変数



void display(void) {   // 表示部分をこの関数で記入
	glClearColor(1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT);       // 画面と奥行き情報を初期化
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotated(rotateAngle, 0, 0, 1);
	for (int j = 0; j < 6; j++) {
		glPushMatrix();
		glRotated(j * 60, 0, 0, 1);
		glTranslated(0.86,0, 0);
		for (int i = 0; i < 6; i++) {
			glPushMatrix();
			glColor3d(0.0, 0.0, 0.0);
			glRotated(i * 60, 0, 0, 1);
			glTranslated(0.43, 0, 0);
			j%2==0&&i % 2 == 0||j % 2 == 1 && i % 2 == 1 ? glRotated(rotateAngle, 0, 0, 1) : glRotated(-rotateAngle, 0, 0, 1);
			glCallList(ID_DRAW_BALL);
			glPopMatrix();
		}
		glPopMatrix();
	}
	glutSwapBuffers(); // バッファの入れ替え
}

// 一定時間ごとに呼び出される関数
void timer(int value) {
	rotateAngle++; // 回転角度の更新

	glutPostRedisplay(); // 再描画命令
	glutTimerFunc(100, timer, 0); // 100ミリ秒後に自身を実行する
}

// ディスプレイリストを作成する
void buildDisplayList() {
	glNewList(ID_DRAW_BALL, GL_COMPILE);
	glScaled(0.4, 0.4, 1.0);
	for (int i = 0; i<20; i++) {  //1つ18度、20個分回して歯車を作る

		glRotated(18, 0, 0, 1);

		glBegin(GL_POLYGON);
		double deg = 9 * M_PI / 180;
		glVertex2d(cos(deg) * 0 - sin(deg)*0.05, sin(deg) * 0 + cos(deg)*0.05);  //1つ目の点
		glVertex2d(0, 0.05);  //2つ目の点
		deg = -9 * M_PI / 180;
		glVertex2d(cos(deg) * 0 - sin(deg)*0.05, sin(deg) * 0 + cos(deg)*0.05);  //3つ目の点
		deg = -9 * M_PI / 180;
		double x, y;
		glVertex2d(x = cos(deg) * 0 - sin(deg)*0.5, y = sin(deg) * 0 + cos(deg)*0.5);  //4つ目の点
		deg = -80 * M_PI / 180;
		glVertex2d(cos(deg) * (0 - x) - sin(deg)*(0.5 - y) + x, sin(deg) * (0 - x) + cos(deg)*(0.5 - y) + y);  //5つ目の点
		deg = 80 * M_PI / 180;
		glVertex2d(cos(deg) * x - sin(deg)*(y - 0.5), sin(deg) * x + cos(deg)*(y - 0.5) + 0.5);  //6つ目の点
		glVertex2d(0, 0.5);  //7つ目の点
		deg = 9 * M_PI / 180;
		glVertex2d(cos(deg) * 0 - sin(deg)*0.5, sin(deg) * 0 + cos(deg)*0.5);  //8つ目の点
		glEnd();
	}

	glEndList();
}


// メインプログラム
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutInitWindowSize(400, 400);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定

	glutTimerFunc(100, timer, 0); // 100ミリ秒後に実行する関数の指定

	buildDisplayList();

	rotateAngle = 0;                // 変数の初期値の設定

	glutMainLoop();                 // イベント待ち
	return 0;
}
