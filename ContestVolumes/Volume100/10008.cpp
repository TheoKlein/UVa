#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    int n, frequency[26] = { 0 }, max = 0;
    cin >> n;
    while(n-- != -1){
        string input;
        getline(cin, input);
        for(int i = 0 ; i < input.length(); ++i){
            if(isalpha(input[i])){
                frequency[toupper(input[i]) - 'A']++;
                if(frequency[toupper(input[i]) - 'A'] > max)
                    max = frequency[toupper(input[i]) - 'A'];
            }
        }
    }
    for(int i = max ; i > 0 ; --i){
        for(int j = 0 ; j < 26 ; ++j){
            if(frequency[j] == i)
                cout << char(j + 65) << " " << frequency[j] << endl;
        }
    }
}
