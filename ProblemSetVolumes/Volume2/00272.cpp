#include <iostream>
#include <string>

using namespace std;

int main () {
  string input;
  bool quote = false;
  while( getline(cin , input) ){
    for(int i = 0 ; i < input.length() ; ++i){
      if(input[i] == '"'){
        if(quote){
          cout << "''";
          quote = false;
        }else{
          cout << "``";
          quote = true;
        }
      }else{
        cout << input[i];
      }
    }
    cout << endl;
  }
}

