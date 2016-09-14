#include <iostream>
#include <string>
using namespace std;

int main(){
    string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string input;
    while(getline(cin, input)){
        for(int i = 0 ; i < input.length(); ++i){
            if(input[i] == ' ')
                cout << " ";
            else{
                for(int j = 0 ; j < keyboard.length(); ++j){
                    if(keyboard[j] == input[i]){
                        cout << keyboard[j - 2];
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}
