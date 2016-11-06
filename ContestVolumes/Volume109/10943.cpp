#include <iostream>
#define MOD 1000000
using namespace std;

int main(){
    unsigned int board[101][101] = { 0 };
    for(int i = 1 ; i < 101 ; i++){
        board[i][1] = 1;
        board[1][i] = i;
    }
    for(int i = 2 ; i < 101 ; i++){
        for(int j = 2 ; j < 101 ; j++)
            board[i][j] = (board[i - 1][j] % MOD + board[i][j - 1] % MOD) % MOD;
    }

    int n, k;
    while(cin >> n >> k && (n != 0 || k != 0))
        cout << board[n][k] % MOD << endl;
}
