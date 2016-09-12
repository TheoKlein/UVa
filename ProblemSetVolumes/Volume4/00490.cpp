#include <iostream>

using namespace std;

int main() {
    int index = 0;
    unsigned long int max = 0;
    string input;
    char array[100][100] = {' ' , ' '};
    while(getline(cin , input)){
        for(int i = 0 ; i < input.length() ; ++i)
            array[index][i] = input[i];
        if(input.length() > max)
            max = input.length();
        index++;
    }
    for(int i = 0 ; i < max ; ++i){
        for(int j = index - 1 ; j >= 0 ; --j){
            if(array[j][i] == '\0')
                cout << ' ';
            else
                cout << array[j][i];
        }
        cout << endl;
    }
}
