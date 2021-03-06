#include <stdio.h>
#include <math.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif
#include <time.h>

struct point
{
    double x[3];
};
struct edge
{ 
    struct point a, b;
};
struct plane
{
    // k[0]x+k[1]y+k[2]z=d
    double k[3], d;
};
typedef struct point point;
typedef struct edge edge;
typedef struct plane plane;

#define PI 3.14159265358
point cubePoint[8] = {{0.5, 0.5, -0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}, {-0.5, 0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5}, {-0.5, -0.5, 0.5}, {-0.5, -0.5, -0.5}};
int cubePlaneGroup[6][4] = {{0, 1, 5, 4}, {1, 2, 6, 5}, {2, 3, 7, 6}, {3, 0, 4, 7}, {0, 1, 2, 3}, {4, 5, 6, 7}};
int PlaneNumber[6];
int table[6][6] = {{2, 4, 5, 3, 1, 6}, {1, 3, 6, 4, 2, 5}, {1, 5, 6, 2, 3, 4}, {2, 6, 5, 1, 4, 3}, {4, 6, 3, 1, 5, 2}, {3, 5, 4, 2, 6, 1}};
double cube2dPoint[8][2];
int cubeDisplayPoint[8][2];
point camera = {2, 1.5, 2};
point cameraY = {-2, 2, 2};
const double cameraR = 3.5;
double displayPlaneSize = 4;
const int displayPixelSize = 30;
// 终端英文字符宽高比例需要1:2
const int displayPixelWidth = 60;
char displayBuff[30][60];
double angleA = -PI / 4;
double angleB = PI / 4;
double speed = 0.05;

void draw();

#ifndef _WIN32
#include <termios.h>
#include <unistd.h>
char getch()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON; // local modes = Non Canonical mode
    old.c_lflag &= ~ECHO;   // local modes = Disable echo.
    old.c_cc[VMIN] = 1;     // control chars (MIN value) = 1
    old.c_cc[VTIME] = 0;    // control chars (TIME value) = 0 (No time)
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON; // local modes = Canonical mode
    old.c_lflag |= ECHO;   // local modes = Enable echo.
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
#endif

plane getDisplayPlane()
{
    double d = 0;
    for (int i = 0; i < 3; i++)
    {
        d += camera.x[i] * camera.x[i];
    }
    return (plane){{camera.x[0], camera.x[1], camera.x[2]}, -d};
}

point getDisplayCenter()
{
    return (point){-camera.x[0], -camera.x[1], -camera.x[2]};
}

point getVector(point a, point b)
{
    return (point){b.x[0] - a.x[0], b.x[1] - a.x[1], b.x[2] - a.x[2]};
}

double innerProduct(point a, point b)
{
    double res = 0;
    for (int i = 0; i < 3; i++)
    {
        res += a.x[i] * b.x[i];
    }
    return res;
}

point crossProduct(point a, point b)
{
    return (point){a.x[1] * b.x[2] - a.x[2] * b.x[1], a.x[2] * b.x[0] - a.x[0] * b.x[2], a.x[0] * b.x[1] - a.x[1] * b.x[0]};
}

double getLength(point a)
{
    double sqr = 0;
    for (int i = 0; i < 3; i++)
    {
        sqr += a.x[i] * a.x[i];
    }
    return sqrt(sqr);
}

point getPoint(edge a, plane b)
{
    point res;
    for (int i = 0; i < 3; i++)
    {
        double k = b.k[i];
        double d = b.d;
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                k += b.k[j] * (a.a.x[j] - a.b.x[j]) / (a.a.x[i] - a.b.x[i]);
                d -= b.k[j] * (a.b.x[j] * a.a.x[i] - a.a.x[j] * a.b.x[i]) / (a.a.x[i] - a.b.x[i]);
            }
        }
        res.x[i] = d / k;
    }
    return res;
}

void initCamera()
{

    camera.x[0] = cos(angleA) * cos(angleB) * cameraR;
    camera.x[1] = sin(angleA) * cameraR;
    camera.x[2] = cos(angleA) * sin(angleB) * cameraR;

    cameraY.x[0] = cos(angleA + PI / 2) * cos(angleB) * cameraR;
    cameraY.x[1] = sin(angleA + PI / 2) * cameraR;
    cameraY.x[2] = cos(angleA + PI / 2) * sin(angleB) * cameraR;
}

void drawLine(const int a[2], const int b[2])
{

    if (a[0] == b[0] && a[1] == b[1])
    {
        return;
    }
    int step[2];
    for (int i = 0; i < 2; i++)
    {
        if (a[i] - b[i] > 0)
        {
            step[i] = -1;
        }
        else if (a[i] - b[i] == 0)
        {
            step[i] = 0;
        }
        else
        {
            step[i] = 1;
        }
    }
    if (abs(a[0] - b[0]) > abs(a[1] - b[1]))
    {
        int j = a[1];
        double k = (a[1] - b[1]) * 1.0 / (a[0] - b[0]);
        for (int i = a[0] + step[0]; (b[0] - i) / step[0] > 0; i += step[0])
        {
            if (fabs(1.0 * (j + step[1] - a[1]) / (i - a[0]) - k) < fabs(1.0 * (j - a[1]) / (i - a[0]) - k))
            {
                j += step[1];
            }
            if (displayBuff[i][j] == 0)
            {
                displayBuff[i][j] = '*';
            }
        }
    }
    else
    {
        int j = a[0];
        double k = (a[0] - b[0]) * 1.0 / (a[1] - b[1]);
        for (int i = a[1] + step[1]; (b[1] - i) / step[1] > 0; i += step[1])
        {
            if (fabs(1.0 * (j + step[0] - a[0]) / (i - a[1]) - k) < fabs(1.0 * (j - a[0]) / (i - a[1]) - k))
            {
                j += step[0];
            }
            if (displayBuff[j][i] == 0)
            {
                displayBuff[j][i] = '*';
            }
        }
    }
}

void fswap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void fill(int r, int c, char ch)
{
    if (r < 1 || c < 1 || r >= displayPixelSize || c >= displayPixelWidth)
    {
        return;
    }
    if (displayBuff[r][c] != 0)
    {
        return;
    }
    displayBuff[r][c] = ch;
    fill(r + 1, c, ch);
    fill(r - 1, c, ch);
    fill(r, c + 1, ch);
    fill(r, c - 1, ch);
}

int sqr(int x)
{
    return x * 2;
}

void drawCube()
{
    memset(displayBuff, 0, sizeof(displayBuff));
    double dis[6][2] = {0};

    for (int i = 0; i < 6; i++)
    {
        dis[i][0] = i;
        for (int j = 0; j < 4; j++)
        {
            dis[i][1] += getLength(getVector(camera, cubePoint[cubePlaneGroup[i][j]]));
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (dis[j][1] > dis[j + 1][1])
            {
                fswap(&dis[j][1], &dis[j + 1][1]);
                fswap(&dis[j][0], &dis[j + 1][0]);
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        int planeId = (int)dis[i][0];
        int hide = 0;
        int xy[4][2];
        for (int j = 0; j < 4; j++)
        {
            memcpy(xy[j], cubeDisplayPoint[cubePlaneGroup[planeId][j]], sizeof(xy[j]));
        }
        for (int j = 0; j < 4; j++)
        {
            if (displayBuff[xy[j][0]][xy[j][1]] != 0 && displayBuff[xy[j][0]][xy[j][1]] != '+')
            {
                hide = 1;
            }
        }
        if (hide)
        {
            continue;
        }

        for (int j = 0; j < 4; j++)
        {
            drawLine(xy[j], xy[(j + 1) % 4]);
        }
        for (int j = 0; j < 4; j++)
        {
            displayBuff[xy[j][0]][xy[j][1]] = '+';
        }
        int center[2];
        if (sqr(xy[0][0] - xy[2][0]) + sqr(xy[0][1] - xy[2][1]) > sqr(xy[1][0] - xy[3][0]) + sqr(xy[1][1] - xy[3][1]))
        {
            center[0] = (xy[0][0] + xy[2][0]) / 2.0 + 0.5;
            center[1] = (xy[0][1] + xy[2][1]) / 2.0 + 0.5;
        }
        else
        {
            center[0] = (xy[1][0] + xy[3][0]) / 2.0 + 0.5;
            center[1] = (xy[1][1] + xy[3][1]) / 2.0 + 0.5;
        }
        fill(center[0], center[1], ' ');
        displayBuff[center[0]][center[1]] = '0' + PlaneNumber[planeId];
    }
}

void randomCast()
{
    int tableIdx = rand() % 6;
    int offset = rand();
    for (int i = 0; i < 4; i++)
    {
        PlaneNumber[i] = table[tableIdx][(i + offset) % 4];
    }
    for (int i = 4; i < 6; i++)
    {
        PlaneNumber[i] = table[tableIdx][i];
    }
}

void cls()
{
#ifdef _WIN32
    COORD pos = {0, 0};
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, pos);
#endif
#ifndef _WIN32
    printf("\033c");
#endif
}

void draw()
{
    initCamera();
    for (int i = 0; i < 8; i++)
    {
        point p = getPoint((edge){camera, cubePoint[i]}, getDisplayPlane());
        point v = getVector(getDisplayCenter(), p);
        double vlen = getLength(v);
        double cos = innerProduct(v, cameraY) / getLength(cameraY) / vlen;
        double sin = sqrt(fabs(1 - cos * cos));
        int largeThanPi = innerProduct(crossProduct(cameraY, v), camera) < 0;
        double y = cos * vlen;
        double x = -sin * vlen;
        if (largeThanPi)
        {
            x *= -1;
        }
        cube2dPoint[i][0] = x;
        cube2dPoint[i][1] = y;
        cubeDisplayPoint[i][1] = ((x + displayPlaneSize / 2) / displayPlaneSize * displayPixelSize * 2 + 0.5);
        cubeDisplayPoint[i][0] = ((y + displayPlaneSize / 2) / displayPlaneSize * displayPixelSize + 0.5);
    }
    drawCube();
    char output[displayPixelSize * displayPixelSize * 2 + displayPixelSize + 1];
    int idx = 0;
    for (int i = 0; i < displayPixelSize; i++)
    {
        for (int j = 0; j < displayPixelSize * 2; j++)
        {
            if (displayBuff[i][j] == 0)
            {
                displayBuff[i][j] = '.';
            }
            output[idx++] = displayBuff[i][j];
        }
        output[idx++] = '\n';
    }
    output[idx++] = 0;
    cls();
    printf("%s", output);
}
void start()
{
    while (1)
    {
        int key = getch();
        switch (key)
        {
        case 27:
        {
            exit(0);
        }
        case 'w':
        {
            angleA -= speed;
            break;
        }
        case 's':
        {
            angleA += speed;
            break;
        }
        case 'a':
        {
            angleB += speed;
            break;
        }
        case 'd':
        {
            angleB -= speed;
            break;
        }
        case 'r':
            randomCast();
            break;
        };
        draw();
    }
}

int main()
{
#ifdef _WIN32
    system("cls");
#endif
    srand(time(0));
    randomCast();
    draw();
    start();
}