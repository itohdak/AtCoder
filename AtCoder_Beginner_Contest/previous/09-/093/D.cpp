#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int Q;
  cin >> Q;
  for(int i=0; i<Q; i++){
    ll A, B;
    cin >> A >> B;
    if(A > B){
      ll tmp = A;
      A = B;
      B = tmp;
    }
    ll M = A * B;
    if(M == 1){
      cout << 0 << endl;
    } else {
      // ll C = floor(sqrt(M-1));
      ll C = sqrt(M);
      if(C * C == M) C--;
      ll ret = C * 2;
      if(C == (M-1)/C) ret--;
      if(A <= C) ret--;
      cout << ret << endl;
    }
  }
  return 0;
}
