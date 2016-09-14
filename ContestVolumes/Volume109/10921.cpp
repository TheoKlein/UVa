#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string input;
    while(cin >> input){
        string value = "22233344455566677778889999";
        for(int i = 0 ; i < input.length() ; ++i){
            if(isalpha(input[i]))
                cout << (char)value[(int)(input[i] - 'A')];
            else
                cout << input[i];
        }
        cout << endl;
    }
}
