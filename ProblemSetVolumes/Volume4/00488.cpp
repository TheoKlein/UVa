#include <iostream>

using namespace std;

int main(){
    int n;
    bool line = false;
    
    cin >> n;
    while(n-- != 0){
        int A, F;
        cin >> A >> F;

        for(int times = 0 ; times < F ; ++times){
            if(line)
                cout << endl;
            else
                line = true;

            for(int i = 1 ; i <= A ; ++i){
                for(int j = 1 ; j <= i ; ++j)
                    cout << i;
                cout << endl;
            }
            for(int i = A - 1; i >= 1 ; --i){
                for(int j = i ; j >= 1 ; --j)
                    cout << i;
                cout << endl;
            }
        }
    }
}
