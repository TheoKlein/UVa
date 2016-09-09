#include <iostream>
#define SIZE 50

int fib( int *  );

using namespace std;

int main(){
    int n ;
    cin >> n;
    while(n-- > 0){
        int num;
        cin >> num;
        cout << num << " = ";

        int length = fib(&num), result[length + 1];
        for(int i = 0 ; i < length ; ++i)
            result[i] = 0;
        result[length] = 1;

        while(num > 0)
            result[fib(&num)] = 1;
        for(int i = length ; i >= 0 ; --i)
            cout << result[i];
        cout << " (fib)" << endl;
    } 
}

int fib( int *num ){
    int fib[SIZE] = { 0 }, i = 2;
    fib[0] = 0, fib[1] = 1, fib[2] = 1;
    while(fib[i] <= *num){
        fib[i + 1] = fib[i] + fib[i - 1];
        i++;
    }
    *num -= fib[i - 1];
    return i - 3;
}
