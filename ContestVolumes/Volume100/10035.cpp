#include <iostream>
#include <string>

using namespace std;

int main() {
    string input1 , input2;
    while(cin >> input1 >> input2){
        int num1[10] = {0}, num2[10]  = {0}, count = 0;
        if(input1 == "0" && input2 == "0")
            break;
        for(long int i = input1.length() - 1  , j = 0 ; i >= 0 ; --i , ++j)
            num1[i] = input1[j] - 48;
        for(long int i = input2.length() - 1  , j = 0 ; i >= 0 ; --i , ++j)
            num2[i] = input2[j] - 48;
        
        for(int i = 0 ; i < 10 ; ++i){
            num1[i] += num2[i];
            if(num1[i] >= 10){
                num1[i] -= 10;
                num1[i + 1]++;
                count++;
            }
        }
        if(count == 0)
            cout << "No carry operation." << endl;
        else if(count == 1)
            cout << count << " carry operation." << endl;
        else
            cout << count << " carry operations." << endl;
    }
}
