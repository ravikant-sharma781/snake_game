#include <iostream>
#include <conio.h>
using namespace std;

int gameOver;
const int height = 20;
const int width = 20;

int x, y, fruitX, fruitY, score;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "#";
            }
            if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitY)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            if (j == width - 1)
            {
                cout << "#";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout<<"Score: "<<score<<endl;
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }

        if (x > width || x < 0 || y > height || y < 0)
        {
            gameOver = true;
        }
        if (x == fruitX || y == fruitY)
        {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
        }
    }
}

void logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
}

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
    }

    return 0;
}
