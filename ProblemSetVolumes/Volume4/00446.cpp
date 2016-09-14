#include <iostream>
#include <iomanip>
using namespace std;
string binary(int);

int main(){
    int n;
    cin >> n;
    while(n-- != 0){
        int a, b, sum = 0;
        char sign;
        cin >> hex >> a >> sign >> b;

        if(sign == '+')
            sum = a + b;
        else
            sum = a - b;

        cout << binary(a) << " "<< sign << " " << binary(b) << " = " << sum << endl;
    }
}

string binary(int n){
    string result = "";
    while(n > 0){
        result = to_string(n % 2) + result;
        n /= 2;
    }
    while(result.length() < 13)
        result = '0' + result;
    return result;
}
