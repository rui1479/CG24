#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "../utils/primitive.hpp"
#include "../utils/point.hpp"
#include "../utils/list.hpp"
#include "../tinyXML/tinyxml.h"
#include "config.hpp"
#include "math.h"

using namespace std;

// Códigos de cores
#define RED 1.0f,0.0f,0.0f
#define GREEN 0.0f,1.0f,0.0f
#define BLUE 0.0f,0.0f,1.0f
#define YELLOW 1.0f, 1.0f, 0.0f
#define CYAN 0.0f, 1.0f, 1.0f
#define WHITE 1.0f, 1.0f, 1.0f

// Variáveis da câmara
float camx = 5.0f;
float camy = 5.0f;
float camz = 5.0f;
float lookAtx = 0.0f;
float lookAty = 0.0f;
float lookAtz = 0.0f;
float upx = 0.0f;
float upy = 1.0f;
float upz = 0.0f;
float posx = 0, posz = 0, angle = 0, scalex = 1, scaley = 1, scalez = 1;

int mode = GL_LINE;

Config configuration = NULL;
List figuras = NULL;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void drawFiguras(List figs){
    List temp = figs;
    while(getNext(temp)){
        Primitive pri = (Primitive)getData(temp);
        List pontos = getPontos(pri);
        List tempPontos = pontos;
        while(getNext(tempPontos)) {
            Point ponto = (Point)getData(tempPontos);
            glVertex3f(getX(ponto), getY(ponto), getZ(ponto));
            tempPontos = getNext(tempPontos);
        }
        temp = getNext(temp);
    }
}

void draw_axis() {
    glBegin(GL_LINES);
    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-100.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -100.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
}

void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(camx, camy, camz,
        lookAtx, lookAty, lookAtz,
        upx, upy, upz);

    // put drawing instructions here
    // linhas dos eixos
    draw_axis();
    // put the geometric transformations here;
    glTranslatef(posx, 0.0, posz);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glScalef(scalex, scaley, scalez);

	// figuras
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	glBegin(GL_TRIANGLES);
	drawFiguras(figuras);
    glEnd();
	
	// End of frame
	glutSwapBuffers();
}

// write function to process keyboard events

// Só altera a posição da camera, para debug.
void specKeyProc(int key_code, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        camy += 1;
        break;
    case GLUT_KEY_DOWN:
        camy -= 1;
        break;
    case GLUT_KEY_LEFT:
        camx -= 1;
        break;
    case GLUT_KEY_RIGHT:
        camx += 1;
        break;
    }
    glutPostRedisplay();
}

// Só altera a posição da camera, para debug, e altera os modes para GL_FILL, GL_LINES, GL_POINT
void keyProc(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        posx -= 0.1;
        break;
    case 'd':
        posx += 0.1;
        break;
    case 's':
        posz += 0.1;
        break;
    case 'w':
        posz -= 0.1;
        break;
    case 'q':
        angle -= 15;
        break;
    case 'e':
        angle += 15;
        break;
    case 'i':
        scalez += 0.1;
        break;
    case 'k':
        scalez -= 0.1;
        break;
    case 'j':
        scalex -= 0.1;
        break;
    case 'l':
        scalex += 0.1;
        break;
    case 'u':
        scaley -= 0.1;
        break;
    case 'o':
        scaley += 0.1;
        break;
    case '+':
        scalex += 0.1;
        scaley += 0.1;
        scalez += 0.1;
        break;
    case '-':
        scalex -= 0.1;
        scaley -= 0.1;
        scalez -= 0.1;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	// Carregamento dos dados das figuras
	configuration = xmlToConfig(argv[1]);
	List models   = getModels(configuration); // !NÃO FAZER DELETE DESTA LISTA! contém as paths dos modelos presentes no ficheiro de configuração
	figuras 	  = newL(); // figuras no ficheiro de configuração
	List temp = models;
    while(getNext(temp)){
		addValueList(figuras, fileToPrimitive((char*)getData(temp)));
        temp = getNext(temp);
	}
	// Carregamento dos dados da câmara
	camx    = getXPosCam(configuration);
	camy    = getYPosCam(configuration);
	camz    = getZPosCam(configuration);
	lookAtx = getXLookAt(configuration);
	lookAty = getYLookAt(configuration);
	lookAtz = getZLookAt(configuration);
	upx 	= getXUp(configuration);
	upy 	= getYUp(configuration);
	upz 	= getZUp(configuration);

	// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Projeto_CG");
		
	// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);


	
	// put here the registration of the keyboard callbacks (por enquanto só mexem na camara como forma de debug)
	glutKeyboardFunc(keyProc);
	glutSpecialFunc(specKeyProc);


	// OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	// enter GLUT's main cycle
	glutMainLoop();
	
	freeL(figuras);
	deleteConfig(configuration); // aqui, a List models já é apagada automaticamente, por isso é que não se pode fazer delete como foi dito na linha "List models = getModels(configuration);..."
	return 1;
}