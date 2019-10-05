#include <cstdlib>
#include <cmath>
#include <vector>
#include <GL/glut.h>

// 2次元ベクトルを扱うためのクラス
class Vector2d {
public:
	double x, y;
	Vector2d() { x = y = 0; }
	Vector2d(double _x, double _y) { x = _x; y = _y; }
	void set(double _x, double _y) { x = _x; y = _y; }

	// 長さを1に正規化する
	void normalize() {
		double len = length();
		x /= len; y /= len;
	}

	// 長さを返す
	double length() { return sqrt(x * x + y * y); }

	// s倍する
	void scale(const double s) { x *= s; y *= s; }

	// 加算の定義
	Vector2d operator+(Vector2d v) { return Vector2d(x + v.x, y + v.y); }

	// 減算の定義
	Vector2d operator-(Vector2d v) { return Vector2d(x - v.x, y - v.y); }

	// 内積の定義
	double operator*(Vector2d v) { return x * v.x + y * v.y; }

	// 代入演算の定義
	Vector2d& operator=(const Vector2d& v) { x = v.x; y = v.y; return (*this); }

	// 加算代入の定義
	Vector2d& operator+=(const Vector2d& v) { x += v.x; y += v.y; return (*this); }

	// 減算代入の定義
	Vector2d& operator-=(const Vector2d& v) { x -= v.x; y -= v.y; return (*this); }

	// 値を出力する
	void print() { printf("Vector2d(%f %f)\n", x, y); }
};

// マイナスの符号の付いたベクトルを扱えるようにするための定義 例：b=(-a); のように記述できる
Vector2d operator-(const Vector2d& v) { return(Vector2d(-v.x, -v.y)); }

// ベクトルと実数の積を扱えるようにするための定義 例： c=5*a+2*b; c=b*3; のように記述できる
Vector2d operator*(const double& k, const Vector2d& v) { return(Vector2d(k*v.x, k*v.y)); }
Vector2d operator*(const Vector2d& v, const double& k) { return(Vector2d(v.x*k, v.y*k)); }

// ベクトルを実数で割る操作を扱えるようにするための定義 例： c=a/2.3; のように記述できる
Vector2d operator/(const Vector2d& v, const double& k) { return(Vector2d(v.x / k, v.y / k)); }

// ================================================================================================


std::vector<Vector2d> g_ControlPoints; // 制御点を格納する

									   // ノットベクトルの要素数 （参考書にあわせて、要素数は10としている）
int NUM_NOT;  //ノットベクトルの要素数の初期値
int g_n = 3;  //次元の初期値
int l;  //ここにセグメント数を保存する

		// ノットベクトル
		// この配列の値を変更することで基底関数が変化する。その結果として形が変わる。
		// 下の例では、一定間隔で値が変化するので、「一様Bスプライン曲線」となる
double g_NotVector[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10,11,12,13,14,15,16,17,18,19};

//ノットベクトルの要素数を求める関数
int leng(void) {
	return sizeof g_NotVector / sizeof g_NotVector[0];
}


// 基底関数 N{i,n}(t)の値を計算する
double getBaseN(int i, int n, double t) {
	if (n == 0) {
		// n が 0 の時だけ t の値に応じて 0 または 1 を返す
		if (t >= g_NotVector[i] && t < g_NotVector[i + 1]) {
			return 1.0;
		}
		return 0;
	}
	else {
		double m = 0;
		if (g_NotVector[i + n] != g_NotVector[i]) {
			m += (t - g_NotVector[i]) / (g_NotVector[i + n] - g_NotVector[i])*getBaseN(i, n - 1, t);
		}
		if (g_NotVector[i + n + 1] != g_NotVector[i + 1]) {
			m += (g_NotVector[i + n + 1] - t) / (g_NotVector[i + n + 1] - g_NotVector[i + 1])*getBaseN(i + 1, n - 1, t);
		}
		return m;
	}
}

// 表示部分をこの関数で記入
void display(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT);     // 画面消去

									  // 制御点の描画
	glPointSize(5);
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (unsigned int i = 0; i < g_ControlPoints.size(); i++) {
		glVertex2d(g_ControlPoints[i].x, g_ControlPoints[i].y);
	}
	glEnd();

	// 制御点を結ぶ線分の描画
	glColor3d(1.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	for (unsigned int i = 0; i < g_ControlPoints.size(); i++) {
		glVertex2d(g_ControlPoints[i].x, g_ControlPoints[i].y);
	}
	glEnd();

	l = g_ControlPoints.size() - g_n;  //(セグメント数)=(制御点数)-(次数) の初期値(制御点をうつたびに1減る)
	NUM_NOT = leng();  // ノットベクトルの要素数を求める

	if (g_ControlPoints.size() >= g_n && g_ControlPoints.size()<NUM_NOT - g_n - 1) {
		//曲線の描画
		glColor3d(0.5, 0.0, 1.0);
		glBegin(GL_LINE_STRIP);
		for (double t = g_NotVector[g_n]; t <= g_NotVector[g_n + l]; t += 0.01) {
			double x = 0, y = 0;
			for (int j = 0; j < g_ControlPoints.size(); j++) {  //シグマの中身
				x += getBaseN(j, g_n, t)*g_ControlPoints[j].x;
				y += getBaseN(j, g_n, t)*g_ControlPoints[j].y;
			}
			glVertex2d(x, y);
		}
		glEnd();

		//これ以降セグメントの境界点の描画
		glPointSize(5);
		glColor3d(0.0, 0.0, 0.0);
		glBegin(GL_POINTS);
		//セグメントの最初の境界点
		int x = 0, y = 0;
		for (int j = 0; j < g_ControlPoints.size(); j++) {  //シグマ
			x += getBaseN(j, g_n, g_NotVector[g_n])*g_ControlPoints[j].x;
			y += getBaseN(j, g_n, g_NotVector[g_n])*g_ControlPoints[j].y;
		}
		glVertex2d(x, y);
		//セグメントの境界点
		for (int i = 0;i < g_ControlPoints.size()-g_n;i++) {
			x = 0, y = 0;
			for (int j = 0; j < g_ControlPoints.size(); j++) {  //シグマ
				x += getBaseN(j, g_n, g_NotVector[g_n + l-i])*g_ControlPoints[j].x;
				y += getBaseN(j, g_n, g_NotVector[g_n + l-i])*g_ControlPoints[j].y;
			}
			glVertex2d(x, y);
	    }
		glEnd();

		double a = 0, b = 0;  //前の点を保存するための変数
		for (double t = g_NotVector[g_n]; t <= g_NotVector[g_n + l]; t += 0.01) {
			double x = 0, y = 0;
			for (int j = 0; j < g_ControlPoints.size(); j++) {  //シグマの中身
				x += getBaseN(j, g_n, t)*g_ControlPoints[j].x;
				y += getBaseN(j, g_n, t)*g_ControlPoints[j].y;
			}
			if (t != g_NotVector[g_n]) {  //最初の1点目は前の点がないので描画しない
				glColor3d(0.5, 0.0, 1.0);
				glBegin(GL_LINE_STRIP);
				glVertex2d(x, y);
				glVertex2d((-b + y) / sqrt(pow(x - a, 2) + pow(y - b, 2)) * 30 + x, (a - x) / sqrt(pow(x - a, 2) + pow(y - b, 2)) * 30 + y);
				glEnd();
			}
			a = x, b = y;  //前の点になる
		}


	}
	glutSwapBuffers();
}

void resizeWindow(int w, int h) {
	h = (h == 0) ? 1 : h;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// ウィンドウ内の座標系設定
	// マウスクリックの座標と描画座標が一致するような正投影
	glOrtho(0, w, h, 0, -10, 10);

	glMatrixMode(GL_MODELVIEW);
}

// キーボードイベント処理
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case 'Q':
	case '\033':
		exit(0);  /* '\033' は ESC の ASCII コード */
	case 'a':
		printf("要素数を入力してください。\n");
		int number;
		scanf_s("%d", &number);
		g_NotVector[number];
		for (int i = 0;i < number;i++) {  //ノットベクトルの要素を入力
			printf("%d番目の要素を入力してください(要素数は%d)\n",i,number);
			double element;
			scanf_s("%lf",&element);
			g_NotVector[i] = element;
		}
		for (int i=0;i < number;i++) {  //入力された要素を照準にソートする(T[i]<T[i+1]の法則より)
			for (int j = i + 1;j < number;j++) {
				if (g_NotVector[i] > g_NotVector[j]) {
					int tmp = g_NotVector[i];
					g_NotVector[i] = g_NotVector[j];
					g_NotVector[j] = tmp;
				}
			}
		}
		for (int k = 0;k < number;k++) {  //入力されたノットベクトルを表示
			printf("%lf,", g_NotVector[k]);
		}

		break;
	default:
		break;
	}
	glutPostRedisplay();
}

// マウスイベント処理
void mouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		switch (button) {
		case GLUT_LEFT_BUTTON:
			// クリックした位置に制御点を追加
			// ノット数を増やせばいくらでも制御点を追加できるが、今回はNUM_NOTの値で固定されているので
			// いくらでも追加できるわけではない
			if (g_ControlPoints.size() < NUM_NOT - g_n - 1) {
				g_ControlPoints.push_back(Vector2d(x, y));
			}
		case GLUT_MIDDLE_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			// 末尾の制御点の削除
			if (!g_ControlPoints.empty()) {
				g_ControlPoints.pop_back();
			}
			break;
		default:
			break;
		}
		glutPostRedisplay(); // 再描画
	}
}

//特殊キーイベント処理
void special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (NUM_NOT >= g_n + g_ControlPoints.size() + 1)  g_n += 1;  //(ノット数)=(制御点)+(次数)+1より次元の上限を決める
		glutDisplayFunc(display);
		break;
	case GLUT_KEY_DOWN:
		if (g_n > 1)  g_n -= 1;  //1次元が最低
		glutDisplayFunc(display);
		break;
	}
	printf("%d次元ベジェ曲線です\n", g_n);
	l = g_ControlPoints.size() - g_n;  //(セグメント数)=(制御点数)-(次数)
	glutPostRedisplay(); // 再描画
}



//マウスドラッグ処理
void motion(int x, int y) {

}

// メインプログラム
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // 描画モードの指定
	glutInitWindowSize(800, 800);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定
	glutReshapeFunc(resizeWindow);  // ウィンドウサイズが変更されたときの関数を指定
	glutKeyboardFunc(keyboard);     // キーボードイベント処理関数を指定
	glutMouseFunc(mouse);           // マウスイベント処理関数を指定
	glutSpecialFunc(special);       // 特殊キーイベント処理関数を指定
	glutMotionFunc(motion);         // マウスドラッグ処理関数を指定
	glutMainLoop();                 // イベント待ち
	return 0;
}
