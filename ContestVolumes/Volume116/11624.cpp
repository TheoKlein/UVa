#include <iostream>
#include <queue>
#define SIZE 1001
#define BIGN 10000000
using namespace std;

struct point{
    int x;
    int y;
    point(int a, int b){
        x = a;
        y = b;
    }
};

int R, C, steps;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char maze[SIZE][SIZE];
int fireMaze[SIZE][SIZE];
int joeMaze[SIZE][SIZE];

queue<point> fire;
queue<point> joe;
queue<point> empty;

void fill(int x, int y, char c, int s){
    if(!(x >= 0 && x < R && y >= 0 && y < C) || maze[x][y] == -1) return;
    if(c == 'F' && s < fireMaze[x][y]){
        fireMaze[x][y] = s;
        point temp(x, y);
        fire.push(temp);
    }else if(c == 'J' && s < joeMaze[x][y]){
        joeMaze[x][y] = s;
        point temp(x, y);
        joe.push(temp);  
    }
}

void BSF(){     
    // fireMaze
    steps = 1;
    while(!fire.empty()){
        queue<point> temp = fire;
        fire = empty;
        while(!temp.empty()){
            point p = temp.front();
            temp.pop();
            int x = p.x, y = p.y;
            for(int k = 0 ; k < 4 ; k++)
                fill(x + dir[k][0], y + dir[k][1], 'F', steps);
        }
        steps++;
    }
    
    // joeMaze
    steps = 1;
    while(!joe.empty()){
        queue<point> temp = joe;
        joe = empty;
        while(!temp.empty()){
            point p = temp.front();
            temp.pop();
            int x = p.x, y = p.y;
            for(int k = 0 ; k < 4 ; k++)
                fill(x + dir[k][0], y + dir[k][1], 'J', steps);
        }
        steps++;
    }

    //check
    int ans = BIGN;
    for(int i = 0 ; i < R ; i++){
        if(maze[i][0] != -1 && fireMaze[i][0] > joeMaze[i][0])
            ans = min(ans, joeMaze[i][0]);
        if(maze[i][C - 1] != -1 && fireMaze[i][C - 1] > joeMaze[i][C - 1])
            ans = min(ans, joeMaze[i][C - 1]);
    }

    for(int i = 0 ; i < C ; i++){
        if(maze[0][i] != -1 && fireMaze[0][i] > joeMaze[0][i])
            ans = min(ans, joeMaze[0][i]);
        if(maze[R - 1][i] != -1 && fireMaze[R - 1][i] > joeMaze[R - 1][i])
            ans = min(ans, joeMaze[R - 1][i]);
    }

    if(ans == BIGN) cout << "IMPOSSIBLE" << endl;
    else cout << ans + 1 << endl;
}

int main(){
    int n, count = 0;
    cin >> n;
    while(n--){        
        cin >> R >> C;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                cin >> maze[i][j];
                point temp(i, j);
                if(maze[i][j] == 'F'){
                    fire.push(temp);
                    joeMaze[i][j] = BIGN;
                    fireMaze[i][j] = 0;
                }else if(maze[i][j] == 'J'){
                    joe.push(temp);
                    joeMaze[i][j] = 0;
                    fireMaze[i][j] = BIGN;
                }else if(maze[i][j] == '#'){
                    fireMaze[i][j] = -1;
                    joeMaze[i][j] = -1;
                }else if(maze[i][j] == '.'){
                    fireMaze[i][j] = BIGN;
                    joeMaze[i][j] = BIGN;
                }
            }
        }
        
        if(count++ == 613){
            cout << "\nFIND!!!!" << endl;
            cout << "R = " << R << " C = " << C << endl;
            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j > C ; j++)
                    cout << maze[i][j];
                cout << endl;
            }
        }
        BSF();
    }
}
