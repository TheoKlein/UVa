#include <iostream>

using namespace std;

class Soda{
public:
  Soda(int = 0 , int = 0 , int = 0);
  void Exchange();
  int getEmpty();
  int getExchange();
  int getDrinked();
private:
  int drinked;
  int empty;
  int exchange;
};

int main (){
  int n;
  cin >> n;
  while(n-- != 0){
    int e, f, c;
    cin >> e >> f >> c;
    Soda Tim(e, f, c);
    while(Tim.getEmpty() >= Tim.getExchange()){
      Tim.Exchange();
    }
    cout << Tim.getDrinked() << endl;
  }
}

Soda::Soda(int e, int f, int c){
  drinked = 0;
  empty = e + f;
  exchange = c;
}

void Soda::Exchange(){
  if(empty >= exchange){
    int temp = empty / exchange;
    if(empty % exchange != 0){
      drinked += temp;
      empty %= exchange;
      empty += temp;
    }else{
      drinked += temp;
      empty = temp;
    }
  }
}

int Soda::getEmpty(){
  return empty;
}

int Soda::getExchange(){
  return exchange;
}

int Soda::getDrinked(){
  return drinked;
}

