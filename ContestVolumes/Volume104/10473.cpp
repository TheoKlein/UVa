#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    string input;
    while(cin >> input){
        if(input[0] == '-')
			break;
		else if(input[0] == '0' && input[1] == 'x'){
            long int output;
            output = strtol(input.c_str(), NULL, 0);
            cout << dec << output << endl;
        }else{
            int num = atoi(input.c_str());
                if(num == -1)
                    break;
                else
				cout << "0x" << uppercase << hex << num << endl;
        }
    }
}
