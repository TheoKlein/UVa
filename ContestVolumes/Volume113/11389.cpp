#include <iostream>
#include <algorithm>
#define SIZE 105
using namespace std;

int n, d, r;
int morning[SIZE], night[SIZE];

int main(){
    while(cin >> n >> d >> r && n != 0 && d != 0 && r != 0){
        for(int i = 0 ; i < n ; i++) cin >> morning[i];
        for(int i = 0 ; i < n ; i++) cin >> night[i];

        sort(morning, morning + n);
        sort(night, night + n);
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(morning[i] + night[n - i - 1] > d)
                ans += (morning[i] + night[n - i - 1] - d) * r;
        }
        cout << ans << endl;
    }
}
