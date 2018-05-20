#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n != 0){
    if(n%10 == 9){
      cout << "Yes" << endl;
      return 0;
    } else {
      n = n / 10;
    }
  }
  cout << "No" << endl;
  return 0;
}

