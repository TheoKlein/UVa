#include <iostream>
#include <cstdio>
using namespace std;

unsigned int reverse(unsigned int num){
    int reverseNum = 0;
    while( num ){
        reverseNum = reverseNum * 10 + num % 10;
        num /= 10;
    }
    return reverseNum;
}

int main(){
    int n;
    cin >> n;
    while(n-- != 0){
        unsigned int times = 0, reverseNum, input;
        cin >> input;
        reverseNum = reverse(input);
        do{
            input += reverseNum;
            times++;
            reverseNum = reverse(input);
        }while(input != reverseNum);
        cout << times << " " << input << endl;
    }
}
