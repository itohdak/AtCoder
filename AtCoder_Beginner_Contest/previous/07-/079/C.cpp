#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int in;
  cin >> in;
  int A, B, C, D;
  A = (in / 1000) % 10;
  B = (in / 100) % 10;
  C = (in / 10) % 10;
  D = (in / 1) % 10;
  int result;
  for(int i=0; i<8; i++){
    int ans = A;
    if((i / 4) % 2 == 1) ans += B;
    else ans -= B;
    if((i / 2) % 2 == 1) ans += C;
    else ans -= C;
    if((i / 1) % 2 == 1) ans += D;
    else ans -= D;
    if(ans == 7){
      result = i;
      break;
    }
  }
  cout << A;
  if((result / 4) % 2 == 1) cout << '+';
  else cout << '-';
  cout << B;
  if((result / 2) % 2 == 1) cout << '+';
  else cout << '-';
  cout << C;
  if((result / 1) % 2 == 1) cout << '+';
  else cout << '-';
  cout << D;
  cout << "=7" << endl;;

  return 0;
}

