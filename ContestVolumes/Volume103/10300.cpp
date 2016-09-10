#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n-- != 0){
        int times;
        double area, num, lv, total = 0;

        cin >> times;
        for(int i = 0 ; i < times ; i++){
            cin >> area >> num >> lv;
            total += (area / num) * lv * num;
        }
        cout << total << endl;
    }
}
