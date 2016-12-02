#include <iostream>
#include <cstring>
#define SIZE 54
using namespace std;

int main(){
    int n, k, m;
    long long int dp[SIZE][SIZE];
    while(cin >> n >> k >> m){
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1 ; i <= k ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int l = 1 ; l <= m ; l++){
                    if(i - 1 >= 0 && j - l >= 0)
                        dp[i][j] += dp[i - 1][j - l];
                }
            }
        }
        cout << dp[k][n] << endl;
    }
}
