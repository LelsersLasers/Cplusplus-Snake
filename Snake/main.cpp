#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;
int fruitX;
int fruitY;
int coinX;
int coinY;
bool gameon = true;
int score = 0;
char dircetion;
int listoftailX [50];
int listoftailY [50];
int lenghtoftail = 0;
clock_t time0;
int frames = -1;
clock_t time1;
double seconds;
time_t time2;
time_t time3;
double secondstwo;

void addtolist()
{
    for (int i = 48; i >= 0; i = i - 1)
    {
        listoftailX[i+1] = listoftailX[i];
        listoftailY[i+1] = listoftailY[i];
    }
    listoftailX[0] = fruitX;
    listoftailY[0] = fruitY;
}

void movement()
{

    if (_kbhit())
    {
        dircetion = _getch();
    }
    if (dircetion == 'w')
        {
            fruitY = fruitY - 1;
        }
        else if (dircetion == 's')
        {
            fruitY = fruitY + 1;
        }
        else if (dircetion == 'a')
        {
            fruitX = fruitX - 1;
        }
        else if (dircetion == 'd')
        {
            fruitX = fruitX + 1;
        }
        else
        {
            fruitY = fruitY ;
        }

}

void logic()
{
    if (fruitX <= 0 || fruitX >= 29 || fruitY <= 0 || fruitY >= 20)
    {
        gameon = false;
    }
    if (fruitX == coinX && fruitY == coinY)
    {
        score = score + 100;
        coinY = rand()% 19 + 1;
        coinX = rand()% 28 + 1;
        lenghtoftail = lenghtoftail + 1;
    }
    for(int i = 1; i <= lenghtoftail; i = i + 1)
        {
            if (fruitY == listoftailY[i] && fruitX == listoftailX[i])
            {
                gameon = false;
                //break;
            }
        }
}

void draw()
{
    frames = frames + 1;
    bool cont;
    system("CLS");
    for (int height = 0; height < 21; height = height + 1)
    {
        for (int length = 0; length < 30; length = length + 1)
        {
            cont = false;
            for(int i = 1; i <= lenghtoftail; i = i + 1)//if height = any y array value and length = any x array value print
            {
                if (height == listoftailY[i] && length == listoftailX[i])
                {
                    cout << "o";
                    cont = true;
                    break;
                }
            }
            if(cont)
            {
                continue;
            }
            if (height == 0)
            {
              cout << "#";
            }
            else if (height == 20)
            {
                cout << "#";
            }
            else if (length == 0)
            {
                cout << "#";
            }
            else if (length == 29)
            {
                cout << "#";
            }
            else if (length == fruitX && height == fruitY)
            {
                cout << "0";
            }
            else if (length == coinX && height == coinY)
            {
                cout << "C";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "" << endl;
    }
    time1 = clock();
    time(&time3);
    seconds = time1 - time0;
    secondstwo = time3 - time2;
    cout << 1/seconds*1000 << " fps   Overall fps "<< frames/secondstwo << endl;
    cout << "score: " << score << endl;
    time0 = clock();
}

int main()
{
    for (int i = 0; i < 50; i = i + 1)
    {
        listoftailX[i] = -1;
        listoftailY[i] = -1;
    }
    srand(time(NULL));
    fruitY = rand()% 19 + 1;
    fruitX = rand()% 28 + 1;
    coinY = rand()% 19 + 1;
    coinX = rand()% 28 + 1;
    draw();
    Sleep(3000);
    time0 = clock();
    time(&time2);
    while (gameon)
    {
        logic();
        movement();
        addtolist();
        draw();
        Sleep(50);
    }
    cout << "You died." << endl;
    cin >> score;
}
