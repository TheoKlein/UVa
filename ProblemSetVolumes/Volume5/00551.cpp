#include <iostream>
#include <string>
#include <stack>
#define SIZE 3005
using namespace std;

string input;
stack<char> charStack;

bool open(char c){
    if(c == '(' || c == '[' || c == '<' || c == '{')
        return true;
    return false;
}

bool close(char c){
    if(c == ')' || c == ']' || c == '>' || c == '}')
        return true;
    return false;
}

int main(){
    while(getline(cin, input)){
        int i, count = 0;
        for(i = 0; i < input.length(); i++){
            count++;
            if(open(input[i])){
                if(input[i] == '(' && input[i + 1] == '*'){
                    charStack.push('/');
                    i++;
                }else
                    charStack.push(input[i]);
            }else if(close(input[i]) || (input[i] == '*' && input[i + 1] == ')')){
                if(charStack.empty()) break;
                if(input[i] == '*' && input[i + 1] == ')'){
                    if(charStack.top() != '/') break;
                    charStack.pop();
                    i++;
                }else if(input[i] == ')'){
                    if(charStack.top() != '(') break;
                    charStack.pop();
                }else if(input[i] == ']'){
                    if(charStack.top() != '[') break;
                    charStack.pop();
                }else if(input[i] == '}'){
                    if(charStack.top() != '{') break;
                    charStack.pop();
                }else if(input[i] == '>'){
                    if(charStack.top() != '<') break;
                    charStack.pop();
                }
            }
        }
        if (i < input.length() || !charStack.empty()) {
            if (i >= input.length() && !charStack.empty()) count++;
            cout << "NO " << count << endl;
        } else cout << "YES" << endl;

        // clear
        while (!charStack.empty()) charStack.pop();
    }
}
