#include <iostream>
#include <cmath>
#include <string>
#define DIGIT 10000

using namespace std;

class HugeInteger
{
public:
    HugeInteger( string );
    
    HugeInteger subtract( HugeInteger );
    
    bool isGreaterThanOrEqualTo( HugeInteger );
    bool isZero();
    void input( const string & );
    void output();
private:
    short integer[ DIGIT ];
};

int main(){
    int n;
    while(cin >> n){
        for(int i = 0 ; i < n ; ++i){
            string a , b;
            cin >> a >> b;
            HugeInteger num1(a);
            HugeInteger num2(b);
            
            if(num1.isGreaterThanOrEqualTo(num2))
                num1.subtract(num2).output();
            else{
                cout << "-";
                num2.subtract(num1).output();
            }
            cout << endl;
        }
    }
}

HugeInteger::HugeInteger( string number ){
    input(number);
}

void HugeInteger::input(const string &number){
    for(int i = 0 ; i < DIGIT ; ++i)
        integer[i] = 0;
    for(long int i = number.length() - 1  , j = 0 ; i >= 0 ; --i , ++j)
        integer[i] = number[j] - 48;
}

void HugeInteger::output(){
    if(this->isZero()){
        cout << "0";
    }else{
        bool zeroCheck = false;
        for(int i = DIGIT - 1 ; i >= 0 ; --i){
            if(zeroCheck)
                cout << integer[i];
            else if(integer[i - 1] != 0)
                zeroCheck = true;
        }
    }
}

bool HugeInteger::isZero(){
    for(int i = 0 ; i < DIGIT ; ++i){
        if(integer[i] != 0)
            return false;
    }
    return true;
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger number){
    int num1First = 0 , num2First = 0;
    for(int i = DIGIT - 1 ; i >= 0 ; --i)
        if(integer[i] != 0){
            num1First = i;
            break;
        }
    for(int i = DIGIT - 1 ; i >= 0 ; --i)
        if(number.integer[i] != 0){
            num2First = i;
            break;
        }
    
    if(num1First > num2First)
        return true;
    else if(num1First < num2First)
        return false;
    else{
        for(int i = num1First ; i >= 0 ; --i){
            if(integer[i] > number.integer[i])
                return true;
            else if(integer[i] < number.integer[i])
                return false;
            else
                continue;
        }
        return true;
    }
}

HugeInteger HugeInteger::subtract(HugeInteger number){
    HugeInteger result("0");
    for(int i = 0 ; i < DIGIT ; ++i){
        if(integer[i] - number.integer[i] < 0){
            result.integer[i] = integer[i] - number.integer[i] + 10;
            integer[i + 1]--;
        }else{
            result.integer[i] = integer[i] - number.integer[i];
        }
    }
    return result;
}
