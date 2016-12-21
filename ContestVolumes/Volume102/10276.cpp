#include <iostream>
#include <cmath>
#define SIZE 50
using namespace std;

int main(){
    int n, num;
    cin >> num;
    while(num--){
        cin >> n;
        int sticks[SIZE] = { 0 }, temp, i, j;
        sticks[0] = 1;
        for(i = 2 ; ; i++) {
            for(j = 0 ; j < n ; j++) {
                temp = sticks[j] + i;
                temp = (int)sqrt(temp);
                if(temp * temp == sticks[j] + i || sticks[j] == 0) {
                    sticks[j] = i;
                    break;
                }
            }
            if(j == n)  break;
        }
        cout << i - 1 << endl;
    }
}
