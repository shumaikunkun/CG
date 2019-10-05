#include <cstdlib>
#include <GL/glut.h>
#define _USE_MATH_DEFINES	// Visual Studio で 円周率として定数 M_PI を使用するため
#include <cmath>

#define M_PI 3.14159265

// 色の情報を格納する共用体
union color {
	struct { float r, g, b, a; };
	float colors[4];
};

// 個々のティーポットの色や、傾き角度に関する情報を保持するための構造体
struct TeapotData {
	color ambient, diffuse, specular;
	float shininess, angle;
};

// グローバル変数（プログラム中のどこからでもアクセスできる変数）には g_ を付けている
const int g_NumTeapots = 8;  //ティーポットの数
TeapotData g_Teapots[g_NumTeapots];

// float型の値は、数字の後ろにfを付ける。末尾のゼロは省略できる
const float g_TeapotSize = 1.f;
const float g_InnerRadius = 6.f;
const float g_OuterRadius = 7.5f;
const float g_HeightAmplitude = 0.8f;
const float g_HeightOffset = 0.2f;  //ティーポットの高さ

const float g_EyeCenterY = 10.f;  //大きければ視点が高くなる
const float g_EyeCenterZ = 30.f;  //大きければ視点が遠くなる
const float g_EyeRadius = 8.f;
float g_EyeY, g_EyeZ;

const int g_AnimationIntervalMsec = 10;

float g_RotationDegree = 0.f;  //動いた角度を保存 0.0 0.3 0.6 0.9 1.2...
const float g_DeltaRotationDegree = 0.3;  //追加していく値

int g_WindowWidth = 512;
int g_WindowHeight = 512;

// 円筒を描画…引数は円の半径、高さ、円の分割数
// glutには円筒を描画するための関数が無いので、独自に準備
void displayCylinder(float radius, float height, int nSlices) {
	// 天頂面
	const float deltaTheta = 2 * M_PI / (float)nSlices;

	glNormal3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, height, 0);
	for (int i = 0; i <= nSlices; i++) {
		const float theta = deltaTheta * i;
		glVertex3f(radius * cosf(theta), height, radius * sinf(theta));
	}
	glEnd();

	// 底面
	glNormal3f(0, -1, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, 0);
	for (int i = 0; i <= nSlices; i++) {
		const float theta = deltaTheta * i;
		glVertex3f(radius * cosf(theta), 0, radius * sinf(theta));
	}
	glEnd();

	// 側面
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= nSlices; i++) {
		const float theta = deltaTheta * i;
		const float cosTheta = cosf(theta);
		const float sinTheta = sinf(theta);
		glNormal3f(cosTheta, 0, sinTheta);
		glVertex3f(radius * cosTheta, height, radius * sinTheta);
		glVertex3f(radius * cosTheta, 0, radius * sinTheta);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 透視投影変換の設定
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, g_WindowWidth / (double)g_WindowHeight, 1, 100.0);

	// モデル座標の操作へモード切り替え
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, g_EyeY, g_EyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	float ambientColor[] = { 0.4f, 0.2f, 0.2f, 1.0f };
	float diffuseColor[] = { 1.f, 0.8f, 0.8f, 1.0f };
	float specularColor[] = { 0.4f, 0.3f, 0.3f, 1.0f };
	float shininess = 5.f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
	glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);



	// 屋根
	glPushMatrix();
	glTranslatef(0, g_HeightAmplitude + g_HeightOffset + 3.f, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(g_OuterRadius, 2.f, 32, 32);
	glPopMatrix();

	// 中心の柱
	glPushMatrix();
	glTranslatef(0, -1.f, 0);
	displayCylinder(0.5f, g_HeightAmplitude + g_HeightOffset + 6.5f, 32);
	glPopMatrix();

	// 土台
	glPushMatrix();
	glTranslatef(0, -2.f, 0);
	displayCylinder(g_OuterRadius, 0.7f, 64);
	glPopMatrix();

	// 屋根の上のティーポット
	glPushMatrix();
	glTranslatef(0, g_HeightAmplitude + g_HeightOffset + 5.5f, 0);
	glRotatef(g_RotationDegree, 0, 1, 0); // 回転させている
	glutSolidTeapot(g_TeapotSize);
	glPopMatrix();

	glRotatef(g_RotationDegree * 10, 0, 1, 0);

	const float deltaTheta = 360 / (float)g_NumTeapots;

	// ティーポットと柱を1つずつ描画する
	for (int i = 0; i < g_NumTeapots; i++) {
		const float thetaDegree = deltaTheta * i; // ティーポットの位置を決めるための角度

		const float thetaRad = thetaDegree * M_PI / 180.f;
		const float xPos = g_InnerRadius * sinf(thetaRad);
		const float zPos = g_InnerRadius * cosf(thetaRad);

		// ティーポットの高さ方向の値
		const float yPos = sin(2*M_PI*(i+ g_RotationDegree/3)/4)+1.2;

										   // ティーポットの色の指定
		glMaterialfv(GL_FRONT, GL_AMBIENT, g_Teapots[i].ambient.colors);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, g_Teapots[i].diffuse.colors);
		glMaterialfv(GL_FRONT, GL_SPECULAR, g_Teapots[i].specular.colors);
		glMaterialfv(GL_FRONT, GL_SHININESS, &g_Teapots[i].shininess);

		// ティーポットの描画
		glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glRotatef(thetaDegree, 0, 1, 0);
		glRotatef(g_Teapots[i].angle, 0, 0, 1);
		glutSolidTeapot(1.2f * g_TeapotSize);
		glPopMatrix();

		// ティーポットを支える柱の色の指定
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientColor);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
		glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);

		// ティーポットを支える柱の描画
		glPushMatrix();
		glTranslatef(xPos, -1.f, zPos);
		displayCylinder(0.3f, yPos + 1.f, 32);
		glPopMatrix();
	}

	glutSwapBuffers();
}

float frand() { return rand() / (float)RAND_MAX; }

// 初期設定を行う関数
void init() {
	glClearColor(1, 1, 1, 1);
	glClearDepth(100.f);

	float lightAmbientColor0[] = { 0.2f, 0.2f, 0.2f, 0.0f };
	float lightDiffuseColor0[] = { 0.4f, 0.4f, 0.4f, 0.0f };
	float lightSpecularColor0[] = { 0.8f, 0.8f, 0.8f, 0.0f };
	float lightPosition0[] = { 5.0f, 5.0f, 8.0f, 0.0f };

	float lightAmbientColor1[] = { 0.2f, 0.2f, 0.2f, 0.0f };
	float lightDiffuseColor1[] = { 0.4f, 0.4f, 0.4f, 0.0f };
	float lightSpecularColor1[] = { 0.8f, 0.8f, 0.8f, 0.0f };
	float lightPosition1[] = { -5.0f, 2.0f, 3.0f, 0.0f };

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbientColor0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuseColor0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecularColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbientColor1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuseColor1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecularColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

	srand(0);

	// 個々のティーポットの色を設定する処理 乱数で決めている
	for (int i = 0; i < g_NumTeapots; i++) {
		g_Teapots[i].ambient.r = 0.2f * frand();
		g_Teapots[i].ambient.g = 0.2f * frand();
		g_Teapots[i].ambient.b = 0.2f * frand();
		g_Teapots[i].ambient.a = 1.f;

		g_Teapots[i].diffuse.r = 0.2f * frand() + 0.8f;
		g_Teapots[i].diffuse.g = 0.2f * frand() + 0.8f;
		g_Teapots[i].diffuse.b = 0.2f * frand() + 0.8f;
		g_Teapots[i].diffuse.a = 1.f;

		g_Teapots[i].specular.r = 0.3f * frand() + 0.2f;
		g_Teapots[i].specular.g = 0.3f * frand() + 0.2f;
		g_Teapots[i].specular.b = 0.3f * frand() + 0.2f;
		g_Teapots[i].specular.a = 1.f;

		g_Teapots[i].shininess = 2.f + 30 * frand();

		g_Teapots[i].angle = 15 * (2.f * frand() - 1.f);
	}

	glEnable(GL_DEPTH_TEST);
}

// 一定時間ごとに実行される関数
void timer(int val) {
	// 回転角度の更新
	g_RotationDegree += g_DeltaRotationDegree;

	const float rotationRad = 2.f * g_RotationDegree * M_PI / 180.f;

	g_EyeY = (sin(g_RotationDegree / 10) + 1) * 10 - 5;  //カメラのy座標は-5.f-15.f
	g_EyeZ = (cos(g_RotationDegree / 10) + 1) * 10 + 30;  //カメラのz座標は30.f-50.f

	glutPostRedisplay();

	glutTimerFunc(g_AnimationIntervalMsec, timer, val);
}

// ウィンドウサイズが変更されたときの処理
void reshape(int w, int h) {
	if (h < 1) return;

	// ビューポートをウィンドウサイズに変更
	glViewport(0, 0, w, h);
	g_WindowWidth = w;
	g_WindowHeight = h;
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(g_WindowWidth, g_WindowHeight);

	// ウィンドウタイトルに表示する文字列を指定する場合
	glutCreateWindow("Teapot Merry-Go-Round");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape); // ウィンドウサイズが変更されたときに実行される関数を指定
	glutTimerFunc(g_AnimationIntervalMsec, timer, 0);

	// 初期設定を行う
	init();

	glutMainLoop();

	return 0;
}
