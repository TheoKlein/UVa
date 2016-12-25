#include <iostream>
#include <cstring>
#define SIZE 20005
using namespace std;

int indexCase = 1, n;
int sum[SIZE];

void readTree(int n){
    int L, R;
    cin >> L;
    if(L != -1){
        sum[n - 1] += L;
        readTree(n - 1);
    }

    cin >> R;
    if(R != -1){
        sum[n + 1] += R;
        readTree(n + 1);
    }
}

int main(){
    while(cin >> n && n != -1){
        bool blank = false;
        memset(sum, 0, sizeof(sum));
        
        sum[10000] = n;
        readTree(10000);
        cout << "Case " << indexCase++ << ":" << endl;
        for(int i = 0 ; i < SIZE ; i++){
            if(sum[i] != 0){
                if(blank) cout << " ";
                cout << sum[i];
                blank = true;
            }
        }
        cout << endl << endl;
    }
}
