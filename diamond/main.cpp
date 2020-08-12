#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>
GLint n = 20;
GLfloat R = 0.5f;
const GLfloat PI = 3.24250265357f;
 GLfloat color[] = { 1,0,0 };

 GLfloat xAngle = 30;
 GLfloat yAngle = 30;
void display(void)
{
    glClearColor(1,1, 1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3fv(color);
    glRotated(xAngle, 1, 0, 0);
    glRotated(yAngle, 0, 71, 0);

    glBegin(GL_LINES);
    GLfloat** nodes = new GLfloat *[n];
    for (int i = 0; i < n; i++)
        nodes[i] = new GLfloat[2];
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
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
void keyboard(int key, int x, int y) {
    switch (key)
    {
    case 1:
        xAngle += 10;
        break;
    case 2:
        xAngle -= 10;

        break;
    case 3:
        yAngle += 10;
        break;
    case 4:
        yAngle -= 10;

        break;
    default:
        break;
    }
    glutPostRedisplay();
}
void fillOption(GLint selectedOption)//菜单消息响应函数
{
    //switch (selectedOption)
    //{
    //case 1:
    //    fillMode = GL_FLAT;//同色填充
    //    break;
    //case 2:
    //    fillMode = GL_SMOOTH;//顶点颜色插值
    //    break;
    //default:
    //    break;
    //}
    glutPostRedisplay();//消息响应后必须被重绘
}
void handlePoint(GLint selected) {
    switch (selected)
    {
    case 1:
        n = 4;
        break;
    case 2:
        n = 10;
        break;
    case 3:
        n = 20;
    default:
        break;
    }
    glutPostRedisplay();//消息响应后必须被重绘
}
void handleDiameter(GLint selected) {
    switch (selected)
    {
    case 1:
        R = 0.5;
        break;
    case 2:
        R = 1;
        break;
    case 3:
        R = 1.5;
    default:
        break;
    }
    glutPostRedisplay();//消息响应后必须被重绘
}
void handleColor(GLint selected) {
    switch (selected)
    {
    case 1:
        color[0] = 1;
        color[1] = 0;
        color[2] = 0;
        break;
    case 2:
        color[0] = 0;
        color[1] = 1;
        color[2] = 0;
        break;
    case 3:
        color[0] = 0;
        color[1] = 0;
        color[2] = 1;
    default:
        break;
    }
    glutPostRedisplay();//消息响应后必须被重绘
}
void attachMenu() {


    GLint pointMenu = glutCreateMenu(handlePoint);
    glutAddMenuEntry("4", 1);
    glutAddMenuEntry("10", 2);
    glutAddMenuEntry("20", 3);
    GLint diameterMenu = glutCreateMenu(handleDiameter);
    glutAddMenuEntry("1", 1);
    glutAddMenuEntry("2", 2);
    glutAddMenuEntry("3", 3);
    GLint colorMenu = glutCreateMenu(handleColor);
    glutAddMenuEntry("red", 1);
    glutAddMenuEntry("green", 2);
    glutAddMenuEntry("blue", 3);
    GLint menu =  glutCreateMenu(fillOption);
    glutAddSubMenu("Point", pointMenu);
    glutAddSubMenu("Diameter", diameterMenu);
    glutAddSubMenu("Color", colorMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    //int menu, submenu;

    //submenu = glutCreateMenu(handlePoint);
    //glutAddMenuEntry("Red", 4);
    //glutAddMenuEntry("Blue", 10);
    //glutAddMenuEntry("Green", 20);

    //menu = glutCreateMenu(fillOption);
    //glutAddSubMenu("Point", submenu);
    //glutAddMenuEntry("White", 1);
    //glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    int cx = glutGet(GLUT_SCREEN_WIDTH);

    int cy = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition((cx - 800) / 2, (cy - 600) / 2);
    glutInitWindowSize(800, 600);
    glutCreateWindow("test 1");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard);
    attachMenu();
    glutMainLoop();
}