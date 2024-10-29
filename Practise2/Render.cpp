// glWinApp.cpp : Defines the entry point for the application.
#include "pch.h"
#include "glWinApp.h"

extern LPCSTR s1, s2, s3;
extern int xCount;
extern int yCount;
extern int btnX1, btnX2, btnY1, btnY2;
extern int LbtnX1, LbtnX2, LbtnY1, LbtnY2;
extern int RbtnX1, RbtnX2, RbtnY1, RbtnY2;

int LoadWindowDefaultFont()
{
    int id = glGenLists(256);
    wglUseFontBitmaps(wglGetCurrentDC(), 0, 256, id);
    return id;
}

void OutText(LPCSTR str, double x, double y, double z = 0)
{
    glRasterPos3d(x, y, z);
    glListBase(idFont);
    glCallLists(strlen(str), GL_UNSIGNED_BYTE, &str[0]);
}

void Render(RECT& clientRect)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    int Width = clientRect.right - clientRect.left;
    int Height = clientRect.bottom - clientRect.top;

    gluOrtho2D(0, Width, 0, Height);
    glViewport(0, 0, Width, Height);

    double rectWidth = Width * 0.75;
    double rectHeight = Height * 0.75;

    double rectLeft = (Width - rectWidth) / 2;
    double rectBottom = (Height - rectHeight) / 2;
    glColor3f(1.0f, 1.0f, 1.0f);

    double xx1 = rectLeft, xx2 = rectLeft, yy2 = rectBottom, yy1 = rectBottom + rectHeight;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2d(rectLeft, rectBottom + rectHeight);
    glVertex2d(rectLeft + rectWidth, rectBottom + rectHeight);
    glVertex2d(rectLeft + rectWidth, rectBottom);
    glVertex2d(rectLeft, rectBottom);
    glEnd();

    glLineWidth(10);
    glColor3f(1.0f, 0.0f, 0.0f);

    double buttonWidth = rectWidth * 0.2;
    double buttonHeight = rectHeight * 0.1;
    double buttonBottom = rectBottom + rectHeight + 10;

    double buttonLeft = (Width - buttonWidth) / 2;
    const char* buttonText = "Add column";
    int textWidth = strlen(buttonText) * 8;
    int textHeight = 12;
    double textX = buttonLeft + (buttonWidth - textWidth) / 2;
    double textY = buttonBottom + (buttonHeight - textHeight) / 2;
    glColor3f(0.75f, 0.75f, 0.0f);

    LbtnX1 = buttonLeft - buttonWidth - 10;
    LbtnX2 = buttonLeft - 10;
    LbtnY1 = Height - buttonBottom - buttonHeight;
    LbtnY2 = Height - buttonBottom;

    DrawButton(buttonLeft, buttonBottom, buttonWidth, buttonHeight, buttonText, textX, textY);

    double yellowButtonLeft = buttonLeft - buttonWidth - 10;
    glColor3f(0.0f, 0.5f, 0.0f);
    //glBegin(GL_QUADS);
    //glVertex2d(yellowButtonLeft, buttonBottom);
    //glVertex2d(yellowButtonLeft + buttonWidth, buttonBottom);
    //glVertex2d(yellowButtonLeft + buttonWidth, buttonBottom + buttonHeight);
    //glVertex2d(yellowButtonLeft, buttonBottom + buttonHeight);
    //glEnd();

    //glColor3f(1.0f, 1.0f, 1.0f);
    const char* yellowButtonText = "Add row";
    textX = yellowButtonLeft + (buttonWidth - strlen(yellowButtonText) * 7.5) / 2;
    //OutText(yellowButtonText, textX, textY);

    btnX1 = buttonLeft;
    btnX2 = buttonLeft + buttonWidth;
    btnY1 = Height - buttonBottom - buttonHeight;
    btnY2 = Height - buttonBottom;

    DrawButton(yellowButtonLeft, buttonBottom, buttonWidth, buttonHeight, yellowButtonText, textX, textY);

    double redButtonRight = buttonLeft + buttonWidth + 10;
    glColor3f(1.0f, 0.0f, 0.0f);
    //glBegin(GL_QUADS);
    //glVertex2d(redButtonRight, buttonBottom);
    //glVertex2d(redButtonRight + buttonWidth, buttonBottom);
    //glVertex2d(redButtonRight + buttonWidth, buttonBottom + buttonHeight);
    //glVertex2d(redButtonRight, buttonBottom + buttonHeight);
    //glEnd();

    //glColor3f(1.0f, 1.0f, 1.0f);
    const char* redButtonText = "Clear";
    textX = redButtonRight + (buttonWidth - strlen(yellowButtonText) * 4) / 2;
    //OutText(redButtonText, textX, textY);

    RbtnX1 = buttonLeft + buttonWidth + 10;
    RbtnX2 = buttonLeft + buttonWidth * 2 + 10;
    RbtnY1 = Height - buttonBottom - buttonHeight;
    RbtnY2 = Height - buttonBottom;

    DrawButton(redButtonRight, buttonBottom, buttonWidth, buttonHeight, redButtonText, textX, textY);


    for (int i = 0; i < xCount; i++)
    {
        for (int j = 0; j < yCount; j++)
        {
            double triangleWidth = rectWidth * 0.05;
            double triangleHeight = rectHeight * 0.05;

            glColor3f(0.0f, 0.44f, 0.75f);

            glBegin(GL_TRIANGLE_STRIP);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 0.5, yy1 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 1.5, yy1 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth, yy1 - triangleHeight - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 0.5, yy1 - triangleHeight * 2 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 1.5, yy1 - triangleHeight * 2 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth, yy1 - triangleHeight - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth, yy1 - triangleHeight - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 0.5, yy1 - j * triangleHeight * 2);
            glEnd();

            glColor3f(1.0f, 0.0f, 0.0f);

            glBegin(GL_TRIANGLES);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 1.5, yy1 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth, yy1 - triangleHeight - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 2, yy1 - triangleHeight - j * triangleHeight * 2);
            glEnd();

            glColor3f(1.0f, 1.0f, 0.0f);

            glBegin(GL_TRIANGLES);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 1.5, yy1 - triangleHeight * 2 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth, yy1 - triangleHeight - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 2, yy1 - triangleHeight - j * triangleHeight * 2);
            glEnd();

            glColor3f(0.0f, 0.75f, 0.28f);

            glBegin(GL_TRIANGLES);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 1.5, yy1 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 2.5, yy1 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 2, yy1 - triangleHeight - j * triangleHeight * 2);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 1.5, yy1 - triangleHeight * 2 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 2.5, yy1 - triangleHeight * 2 - j * triangleHeight * 2);
            glVertex2d(xx1 + i * 2 * triangleWidth + triangleWidth * 2, yy1 - triangleHeight - j * triangleHeight * 2);
            glEnd();
        }
    }

    glColor3f(0.39f, 0.47f, 0.59f);
    glBegin(GL_QUADS);
    glVertex2d(Width * 0.875, Height * 0);
    glVertex2d(Width * 0.875, Height);
    glVertex2d(Width, Height);
    glVertex2d(Width, Height * 0);
    glEnd();
}

void DrawButton(double buttonLeft, double buttonBottom, double buttonWidth, double buttonHeight, const char* buttonText, double textX, double textY)
{
    glBegin(GL_QUADS);
    glVertex2d(buttonLeft, buttonBottom);
    glVertex2d(buttonLeft + buttonWidth, buttonBottom);
    glVertex2d(buttonLeft + buttonWidth, buttonBottom + buttonHeight);
    glVertex2d(buttonLeft, buttonBottom + buttonHeight);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    OutText(buttonText, textX, textY);
}
