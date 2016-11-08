#include <iostream>
#include <queue>
#include <cstring>
#include <fstream>

#define SIZE 9
#define BIGN 10000
using namespace std;

struct point{
    int x;
    int y;
    point(int a, int b){
        x = a;
        y = b;
    }
};

int sX, sY, eX, eY, steps;
int dir[8][2] = {
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
    {1, 2}, {2, 1}, {2, -1}, {1, -2}
};
int BFSmaze[SIZE][SIZE];
bool endPoint = false;
string input;
queue<point> knights;
queue<point> empty;

void init(){
    sX = (int)(input[0] - 'a') + 1;
    sY = (int)(input[1] - '0');
    eX = (int)(input[3] - 'a') + 1;
    eY = (int)(input[4] - '0');

    point start(sX, sY);
    knights.push(start);
    memset(BFSmaze, BIGN, sizeof(BFSmaze[0][0]) * SIZE * SIZE);
    BFSmaze[sX][sY] = 0;
    if(sX == eX && sY == eY) endPoint = true;
}

void fill(int x, int y, int s){
    if(!(x > 0 && x < 9 && y > 0 && y < 9)) return;
    if(s < BFSmaze[x][y]){
        BFSmaze[x][y] = s;
        if(x == eX && y == eY) endPoint = true;
        else{
            point temp(x, y);
            knights.push(temp);
        }
    }
}

void BFS(){
    steps = 1;
    while(!knights.empty() || !endPoint){
        queue<point> temp = knights;
        knights = empty;
        while(!temp.empty()){
            point p = temp.front();
            temp.pop();
            int x = p.x, y = p.y;
            for(int i = 0 ; i < 8 ; i++)
                fill(x + dir[i][0], y + dir[i][1], steps);
        }
        steps++;
    }
    cout << "To get from " << input[0] << input[1] << " to "
         << input[3] << input[4] << " takes " << BFSmaze[eX][eY]
         << " knight moves." << endl;
}

int main(){
    #if defined(JUDGE)
        freopen("p11.in", "r", stdin);
    #endif
    while(getline(cin, input)){
        init();
        BFS();
    }
}
