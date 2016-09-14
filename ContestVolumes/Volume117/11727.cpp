#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int cases = 1 ; cases <= n ; ++cases){
        int input[3];
        for(int i = 0 ; i < 3 ; ++i)
            cin >> input[i];

        for(int i = 0 ; i < 2 ; ++i){
            for(int j = 0 ; j < 2 ; ++j){
                if(input[j] > input[j + 1])
                    swap(input[j], input[j + 1]);
                else
                    continue;
            } 
        }
        cout << "Case " << cases << ": " << input[1] << endl;
    }
}
