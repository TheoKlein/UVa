#include <iostream>
#include <string>
#define SIZE 500

using namespace std;

int main(){
    string input;
    bool line = false;
    while(getline(cin, input)){
        if(line)
            cout << endl;
        else
            line = true;

        int frequency[SIZE] = { 0 }, max = 0;

        for(int i = 0 ; i < input.length() ; ++i){
            frequency[int(input[i])]++;
            if(frequency[int(input[i])] > max)
                max = frequency[int(input[i])];
        }

        for(int i = 1 ; i <= max ; ++i){
            for(int j = SIZE - 1 ; j >= 0 ; --j){
                if(frequency[j] == i)
                    cout << j << " " << i << endl;
            }
        }
    }
}
