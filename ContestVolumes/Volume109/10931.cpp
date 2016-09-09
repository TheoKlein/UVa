#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        int count = 0;
        string binary = "";
        while(n > 0){
            if(n % 2 == 1){
                binary = "1" + binary;
                count++;
            }else
                binary = "0" + binary;
            n /= 2;
        }
        cout << "The parity of " << binary << " is " << count << " (mod 2)." << endl;
    }
}
