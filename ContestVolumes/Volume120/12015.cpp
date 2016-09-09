#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    for(int i = 1 ; i <= num ; ++i){
        string url[10];
        int max = 0, rel[10];
        for(int j = 0 ; j < 10 ; ++j){
            cin >> url[j] >> rel[j];
            if(rel[j] > max)
                max = rel[j];
        }
        
        cout << "Case #" << i << ":" << endl;

        for(int j = 0 ; j < 10 ; ++j){
            if(rel[j] == max)
                cout << url[j] << endl;
        }   
    }
}
