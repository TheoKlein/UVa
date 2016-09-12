#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        int a, b, sum = 0;
        cin >> a >> b;
        for(int j = a ; j <= b ; ++j){
            if(j % 2 != 0)
                sum += j;
        }
        cout << "Case " << i << ": " << sum << endl;
    }
}
