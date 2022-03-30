#include <iostream>
#include <GL/freeglut.h>


static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); // очитска буфера кадра
    glutSwapBuffers(); // Обмен местами буфера кадра и буфера фона
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB); // Фнкция обратного вызова для отрисовки кадров 
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Настройка опций GLUT
    glutInitWindowSize(1024, 768); // Настройка размеров окна
    glutInitWindowPosition(100, 100); // Настройка размеров окна
    glutCreateWindow("Task 1"); // Заголовок окна

    InitializeGlutCallbacks();

    glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Задаём состояние

    glutMainLoop(); // Передача контроля GLUT

    return 0;
}
