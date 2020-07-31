#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n = 20;
const GLfloat R = 0.5f;
const GLfloat PI = 3.1415926535897f;

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    vector<vector<GLfloat>> nodes;

    for (int i = 0; i < n; i++) {
        vector < GLfloat > node;
        node.push_back(R * cos(2 * PI / n * i));
        node.push_back(R * sin(2 * PI / n * i));
        nodes.push_back(node);
    }
    glBegin(GL_LINES);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            glVertex2f(nodes[i][0], nodes[i][1]);
            glVertex2f(nodes[j][0], nodes[j][1]);
        }
    }
    glEnd();
    glFlush();
}
void onKeyPress(unsigned char x,int y ,int z) {
    switch (x)
    {
    case '+':
        n++;
        glutPostRedisplay();
        break;
    case '-':
        if (n == 2) {
            break;
        }
        n--;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Diamond");
    glutDisplayFunc(&myDisplay);
    glutKeyboardFunc(onKeyPress);
    glutMainLoop();
    return 0;
}