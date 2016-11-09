#include <iostream>
#include <cstring>
#define SIZE 500
#define MOD 1000007
using namespace std;
int n, M, N, K, b, r, c, sum, C[SIZE][SIZE];

int main(){
    // init C[][]
    memset(C, 0, sizeof(C));
    for(int i = 0 ; i < SIZE ; i++)
        C[i][0] = C[i][i] = 1;
    for(int i = 2 ; i <= SIZE ; i++){
        for(int j = 1 ; j < i ; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> M  >> N >> K;

        sum = 0;
        for(int j = 0 ; j < 16 ; j++){
            b = 0;
            r = M;
            c = N;
            if(j & 1){
                b++;
                c--;
            }
            if(j & 2){
                b++;
                c--;
            }
            if(j & 4){
                b++;
                r--;
            }
            if(j & 8){
                b++;
                r--;
            }
            if(b & 1)
                sum = (sum + MOD - C[r * c][K]) % MOD;
            else
                sum = (sum + C[r * c][K]) % MOD;
        }
        cout << "Case " << i + 1 << ": " << sum << endl;
    }
}