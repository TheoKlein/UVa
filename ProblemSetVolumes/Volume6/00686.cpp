#include <iostream>
#define SIZE 100000
using namespace std;

bool isPrime(int n){
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(void){
    int n;
    while( cin >> n && n !=0 ){
        int count = 0;
        bool counted[SIZE] = { false };
        for(int i = 2 ; i <= n - 2 ; i++){
            if(isPrime(i) && isPrime(n - i)){
                if(!counted[i] && !counted[n - i]){
                    counted[i] = true;
                    counted[n - i] = true;
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
