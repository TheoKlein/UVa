#include <iostream>

using namespace std;

int main(){
    int n[4], angle;
    while(cin >> n[0] >> n[1] >> n[2] >> n[3]){
        if(!n[0] && !n[1] && !n[2] && !n[3])
            break;

        angle = 1080;
        angle += ((n[0] - n[1]) + 40) % 40 * 9;
        angle += ((n[2] - n[1]) + 40) % 40 * 9;
		angle += ((n[2] - n[3]) + 40) % 40 * 9;
		cout << angle << endl;
    }
}
