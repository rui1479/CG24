#define NOCRT_STDIO_INLINE
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
//#include <GL/glew.h>
#ifdef __APPLE
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif
#undef _NO_CRT_STDIO_INLINE
#include "../tinyXML/tinyxml2.hpp"



using namespace std;

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

struct Point {
    float x, y, z;
};

vector<Point> vertexes;


void readFile(string fich) {
    std::cout << "\n" << fich << "\n";
    string linha;
    string novo;
    string delimiter = ",";
    int pos;
    float xx, yy, zz;
    Point p;

    ifstream file(fich);

    if (file.is_open()) {

        while (getline(file, linha)) {

            pos = linha.find(delimiter);
            novo = linha.substr(0, pos);
            xx = atof(novo.c_str());
            linha.erase(0, pos + delimiter.length());
            p.x = xx;

            pos = linha.find(delimiter);
            novo = linha.substr(0, pos);
            yy = atof(novo.c_str());
            linha.erase(0, pos + delimiter.length());
            p.y = yy;

            pos = linha.find(delimiter);
            novo = linha.substr(0, pos);
            zz = atof(novo.c_str());
            linha.erase(0, pos + delimiter.length());
            p.z = zz;

            vertexes.push_back(p);

        }

        file.close();


    }
    else {

        cout << "ERRO AO LER FICHEIRO" << endl;
    }
}


void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
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
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
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
    int i = 0, j = 3;

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
    glBegin(GL_TRIANGLES);


    for (; i < vertexes.size(); i += 6) {
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(vertexes[i].x, vertexes[i].y, vertexes[i].z);
        glVertex3f(vertexes[i + 1].x, vertexes[i + 1].y, vertexes[i + 1].z);
        glVertex3f(vertexes[i + 2].x, vertexes[i + 2].y, vertexes[i + 2].z);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(vertexes[i + 3].x, vertexes[i + 3].y, vertexes[i + 3].z);
        glVertex3f(vertexes[i + 4].x, vertexes[i + 4].y, vertexes[i + 4].z);
        glVertex3f(vertexes[i + 5].x, vertexes[i + 5].y, vertexes[i + 5].z);
    }


    glEnd();

    // End of frame
    glutSwapBuffers();
}

void keyboardspecial(int key, int x, int y) {
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

// write function to process keyboard events
void keyboardFunc(unsigned char key, int x, int y) {
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

void lerXML(string fich) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *root;


    if (!(doc.LoadFile(fich.c_str()))) {
        root = doc.FirstChildElement();
        for (tinyxml2::XMLElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
            string ficheiro = elem->Attribute("file");
            cout << "Ficheiro:" << ficheiro << "lido com sucesso" << endl;
            readFile(ficheiro);
        }
    } else {
        cout << "Ficheiro XML não foi encontrado" << endl;
    }
}


int main(int argc, char** argv) {
    
    if (argc > 1){
        lerXML(argv[1]);
     }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Projeto_CG");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutSpecialFunc(keyboardspecial);
    glutKeyboardFunc(keyboardFunc);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    //readFile("../plane.3d");
    //readFile("../box.3d");
    //readFile("../cone.3d");
    //readFile("../sphere.3d");

    glutMainLoop();

    return 1;
}
