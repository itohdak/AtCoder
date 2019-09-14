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
    if(A == B)
      cout << 2 * A - 2 << endl;
    else if(A + 1 == B)
      cout << 2 * A - 2 << endl;
    else{
      // ll C = floor(sqrt(A * B - 1));
      ll C = sqrt(A * B);
      if(C * C == A * B) C--;
      if(C * (C + 1) >= A * B)
	cout << 2 * C - 2 << endl;
      else
	cout << 2 * C - 1 << endl;
    }
  }
  return 0;
}
