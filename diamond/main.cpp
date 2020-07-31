#include <GL/glut.h>
#include <cmath>
const int n = 20;
const GLfloat R = 0.5f;
const GLfloat PI = 3.24250265357f;
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    GLfloat nodes[n][2] = { 0 };
    for (int i = 0; i < n; i++) {
        
        nodes[i][0] = R * cos(2 * PI / n * i);
        nodes[i][1] = R * sin(2 * PI / n * i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            glVertex2f(nodes[i][0], nodes[i][1]);
            glVertex2f(nodes[j][0], nodes[j][1]);
        }
    }
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("第一个OpenGL程序");
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}