#include <iostream>

using namespace std;

int ans(long long int n){
    if(n == 1)
        return 1;
    return ans(n / 2) + 1;
}

int main(){
    long long int n;
    while(cin >> n){
        cout << ans(n) << endl;
    }
}
