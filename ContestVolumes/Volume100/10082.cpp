#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string input;
    char encode[] = {"QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./`1234567890-="};
    while(getline(cin, input)){
        char *ptr;
        for(int i = 0 ; i < input.length() ; ++i){
            if(input.at(i) != ' '){
                ptr = strchr(encode, input[i]);
                cout << *(ptr - 1);
            }else
                cout << " ";
        }
        cout << endl;
    }
}
