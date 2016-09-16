#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int ascending( int n ){
    string num = to_string(n);
    sort(num.begin(), num.end());
    return atoi(num.c_str());
}

int descending( int n ){
    string num = to_string(n);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    return atoi(num.c_str());
}

int main(){
    int n;
    while(cin >> n && n != 0){
        bool same = false;
        int times = 0;
        vector<int> temp;

        cout << "Original number was " << n << endl;
        while (!same){
            int a = descending(n),
                b = ascending(n),
                r = a - b;

            cout << a << " - " << b << " = " << r << endl;
            times++;
            n = r;

            if(times > 1){
                for(int j = 0 ; j < temp.size() ; ++j){
                    if(temp[j] == r){
                        cout << "Chain length " << times << endl << endl;
                        same = true;
                        break;
                    }
                }

                if(!same)
                    temp.push_back(r);
            }else
                temp.push_back(r);
        }
    }
}
