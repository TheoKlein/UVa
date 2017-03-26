#include <iostream>
#include <cstdlib>
#define SIZE 10000
using namespace std;

int compare(const void * a, const void * b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int index = 1, n, array[SIZE] = { 0 };
    while(cin >> n){
        array[index] = n;
        qsort(array, index + 1, sizeof(int), compare);

        if(index % 2 != 0)
            cout << array[index / 2 + 1] << endl;
        else
            cout << (array[index / 2] + array[index / 2 + 1]) / 2 << endl;
        index++;
    }
}
