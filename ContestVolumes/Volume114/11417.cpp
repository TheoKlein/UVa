#include <iostream>
using namespace std;

int GCD(int, int);
int main(){
    int n;
    while(cin >> n && n != 0){
        int G = 0;
        for(int i = 1; i < n ; ++i){
            for(int j = i + 1 ; j <= n ; ++j)
                G += GCD(i, j);
        }
        cout << G << endl;
    }
}

int GCD(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
