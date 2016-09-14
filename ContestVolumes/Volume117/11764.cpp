#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        int num, init, high = 0, low = 0;
        cin >> num >> init;

        for(int j = 1 ; j < num ; ++j){
            int temp;
            cin >> temp;
            if(temp > init)
                high++;
            else if(temp < init)
                low++;
            init = temp;
        }

        cout << "Case " << i << ": " << high << " " << low << endl;
    }
}
