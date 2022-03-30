#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO; // создание глобальной переменной для хранения указателя на буфер вершин

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // привязывем буфер, подготавливая его для отрисовки
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);// Настройка восприятия буффера конвеером
    // Первое значение - по умолчанию, второе - количество компонентов
    // 3-й - тип данных, 4-й - не нормализируем данные перед использованием
    //5-й разница в байтах между двумя экземплярами атрибута 

    glDrawArrays(GL_POINTS, 0, 1); // Собственно отрисовка - точка и всего одна

    glDisableVertexAttribArray(0); // откдючаем все атрибуты вершины за ненадобностью

    glutSwapBuffers();
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[1]; // создаём массив из одного объекта структуры Vector3f
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f); // Задаём координаты в центре координатного пространства

    glGenBuffers(1, &VBO); // создаём один объект с использованием указателя, по которому будут храниться данные
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Создаём буффер для хранения вершин
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // Наполняем объект данными (размер в байтах, адрес массива вершин;
    // так как не собираемся изменять значения буфера, то прописываем GL_STATIC_DRAW)
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 02");

    InitializeGlutCallbacks();

    // Инициализируем GLEW после GLUT и проверяем на ошибки
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    CreateVertexBuffer();

    glutMainLoop();

    return 0;
}