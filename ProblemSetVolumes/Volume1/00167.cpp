#include <iostream>
using namespace std;
int board[8][8] = { 0 , 0 };
int queens[8] = { 0 };
int maxResult = 0;

bool conflict(int c, int r){
    for(int i = 0 ; i < c ; i++){
        if(i == c || queens[i] == r)
            return true;
        if(abs(c - i) == abs(queens[i] - r))
            return true;
    }
    return false;
}

void check(int n){
    if(n == 8){
        int total = 0;
        for(int i = 0 ; i < 8 ; i++)
            total += board[i][queens[i]];
        maxResult = max(total, maxResult);
        return;
    }

    for(int i = 0 ; i < 8 ; i++){
        if(!conflict(n, i)){
            queens[n] = i;
            check(n + 1);
        }
    }

}

int main(){
    int n;
    cin >> n;
    while(n--){
        for(int i = 0 ; i < 8 ; i++){
            for (int j = 0 ; j < 8 ; j++)
                cin >> board[i][j];
        }
        check(0);
        cout.width(5);
        cout << right << maxResult << endl;
        maxResult = 0;
    }
}
