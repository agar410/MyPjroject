#include <iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

using namespace std;

struct Point {int x;int y;} P[10], CH[10];
bool compare(Point a, Point b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

int cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int length2(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


bool far_( Point o, Point a, Point b ){

    return length2(o, a) > length2(o, b);
}

int main()
{
    srand((unsigned)time(NULL));
    const int n=10;
    for(int i=0;i<n;i++){
        int a=20,b=50;
        P[i].x=(rand()%(b-a+1))+a;
        P[i].y=(rand()%(b-a+1))+a;
    }

    int start = 0;
    for (int i=0; i<10; ++i){
        if (compare(P[i], P[start]))
            start = i;

    }

    int m = 0;
    CH[m] = P[start];

    int current = start;
    for (int m=1; true; ++m)
    {

        int next = current;
        for (int i=0; i<10; ++i)
        {
            int c = cross(CH[m-1], P[i], P[next]);
            if ((c > 0) ||
                (c == 0) && far_(CH[m-1], P[i], P[next]))
                next = i;
        }

        if (next == start) break;
        CH[m] = P[next];
        current = next;
    }
    for(int i=0;i<10;i++){
        cout<<"("<<CH[i].x<<","<<CH[i].y<<") ";
    }
    int gd=DETECT, gm=2;
    initgraph(&gd,&gm,"c:\\tc");
    //delay(2000);
    setcolor(11);
    for(int i=0;i<10;i++){
        putpixel(P[i].x*5,P[i].y*5,11);
    }
    delay(500);
    for(int i=0;i<10;i++){
    if(CH[i].x>0&&CH[i].y>0&&CH[i+1].x!=0&&CH[i+1].y!=0)
    {
        setcolor(12);
        line(CH[i].x*5,CH[i].y*5,CH[i+1].x*5,CH[i+1].y*5);
        delay(500);
    }
    else if(CH[i+1].x==0&&CH[i+1].y==0)
        {
            setcolor(12);
            line(CH[i].x*5,CH[i].y*5,CH[0].x*5,CH[0].y*5);
            break;
        }
    }
    getch();
    closegraph();
    //cout << "Hello world!" << endl;
    return 0;
}
