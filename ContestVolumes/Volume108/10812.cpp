#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n-- != 0){
        int s, d, a, b;
        cin >> s >> d;
        
        if((s + d) % 2 != 0 || s < d)
            cout << "impossible" << endl;
        else{
            a = (s + d) / 2;
            b = s - a;
            (a >= b)?(cout << a << " " << b << endl):(cout << b << " " << a << endl);
        }
    }
}
