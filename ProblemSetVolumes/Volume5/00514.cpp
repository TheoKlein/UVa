#include <iostream>
#include <cstring>
#include <stack>
#include <fstream>
#define SIZE 1005
#define T

using namespace std;

int A[SIZE], B[SIZE];
int N;

int main(){
    #if defined(T)
        freopen("_Q1.in", "r", stdin);
    #endif
    while(cin >> N && N != 0){
        for(int i = 1 ; i <= N ; i++)
            A[i] = i;

        int first;
        while(cin >> first && first != 0){
            stack<int> numStack;

            B[1] = first;
            for(int i = 2 ; i <= N ; i++)
                cin >> B[i];

            int a = 1, b = 1;
            bool flag = true;
            while(b <= N){
                if(a <= N && A[a] == B[b]){
                    a++;
                    b++;
                }else if(!numStack.empty() && numStack.top() == B[b]){
                    numStack.pop();
                    b++;
                }else if(a <= N){
                    numStack.push(A[a]);
                    a++;
                }else{
                    flag = false;
                    break;
                }
            }
            cout << (flag?"Yes":"No") << endl;
        }
        cout << endl;
    }
}