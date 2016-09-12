#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string input;
    while(cin >> input){
        int sum = 0, prime = true;
        for(int i = 0 ; i < input.length() ; ++i){
            if(isupper(input.at(i)))
                sum += (int)input.at(i) - 38;
            else
                sum += (int)input.at(i) - 96;
        }

        if(sum == 1)
            prime = true;
        else{
            for(int i = 2 ; i * i <= sum ; ++i){
                if(sum % i == 0){
                    prime = false;
                    break;
                }
            }
        }

        cout << (prime?("It is a prime word.\n"):("It is not a prime word.\n"));
    }
}
