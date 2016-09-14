#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n-- != 0){
        string input;
        int frequency[26] = { 0 }, max = 0;
        getline(cin, input);

        for(int i = 0 ; i < input.length() ; ++i){
            if(isalpha(input[i])){
                frequency[(int)(tolower(input[i]) - 'a')]++;
                if(frequency[(int)(tolower(input[i]) - 'a')] > max)
                    max = frequency[(int)(tolower(input[i]) - 'a')];
            }
        }
        for(int i = 0 ; i < 26 ; ++i){
            if(frequency[i] == max)
                cout << (char)(i + 97); 
        }
        cout << endl;
    }
}
