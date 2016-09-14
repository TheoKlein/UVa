#include <iostream>

using namespace std;
void stringToNum( string in , int *array ){
    for(int i = (int)in.length() - 1 , j = 0 ; i >= 0 ; --i , ++j)
        array[i] =in[j] - '0';
}

bool checkZero(int *array){
    for(int i = 0 ; i < 251 ; ++i)
        if(array[i] != 0)
            return false;
    return true;
}

int main() {
    string a , b;
    while(cin >> a >> b){
        int numA[251] = {0}, numB[251] = {0}, result[501] = {0};
        stringToNum(a , numA);
        stringToNum(b , numB);
        
        if(checkZero(numA) || checkZero(numB)){
            cout << "0" << endl;
            continue;
        }
        
        for(int i = 0 , shift = 0 ; i < b.length() ; ++i , ++shift){
            for(int j = 0 , index = 0; j < a.length() ; ++j , ++index){
                result[index + shift] += numB[i] * numA[j];
                while(result[index + shift] > 9){
                    result[index + shift] -= 10;
                    result[index + shift + 1]++;
                }
            }
        }
        
        int index = 500;
        while(result[index] == 0)
            index--;
        for(int i = index; i >= 0 ; --i)
            cout << result[i];
        cout << endl;
    }
}
