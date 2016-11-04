#include <iostream>
#define lowbit(k) ((k) & (-k))
#define SIZE 200001
int num[SIZE], query[SIZE];

int RSQ(int n){
    int sum = 0;
    while(n > 0){
        sum += query[n];
        n -= lowbit(n);
    }
    return sum;
}

using namespace std;
int main(){

    int n, index = 0;
    while(cin >> n && n != 0){
        // init
        for(int i = 0 ; i < SIZE ; i++)
            query[i] = 0;

        for(int i = 1 ; i <= n ; i++)
            cin >> num[i];

        if(++index > 1)
            cout << endl;
        cout << "Case " << index << ":" << endl;


        // Create FT
        for(int i = 1 ; i <= n ; i++){
            int k = i;
            while(k <= n){
                query[k] += num[i];
                k += lowbit(k);
            }
        }

        string action;
        while(cin >> action && action != "END"){
            int x, y;
            cin >> x >> y;
            if(action == "M"){
                cout << RSQ(y) - RSQ(x - 1) << endl;
            }else if(action == "S"){
                int k = x;
                while(k <= n){
                    query[k] += y - num[x];
                    k += lowbit(k);
                }
                num[x] = y;
            }
        }
    }  
}

