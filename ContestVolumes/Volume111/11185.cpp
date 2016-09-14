#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n && n >= 0){
        if(n == 0)
            cout << "0" << endl;
        else{
            string output = "";
            while(n > 0){
                output = to_string(n % 3) + output;
                n /= 3;
            }

            cout << output << endl;
        }
    }
}
