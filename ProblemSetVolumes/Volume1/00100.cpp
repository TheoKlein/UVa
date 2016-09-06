#include <iostream>

using namespace std;

int main(){
    int i,j;
    
    while (cin >> i >> j){
        int ni = i;
        int nj = j;
        
        if ( i > j ) {
            int temp = i;
            i = j;
            j = temp;
        }
        int max = 0;
        
        while (i <= j ){
            unsigned int n = i;
            int length = 1;
            while ( n != 1 ) {
                if ( n % 2 == 1 ) {
                    n = 3 * n + 1;
                    n /= 2;
                    length += 2;
                }
                else {
                    n /= 2;
                    length++;
                }
            }
            if ( length > max ){
                max = length;
            }
            i++;
        }
        if (ni > nj){
            int temp = ni;
            ni = nj;
            nj = temp;
        }
        cout << ni << " " << nj << " " << max << endl;
    }
}
