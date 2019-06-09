#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  ll ret = 0;
  if(K % 2 == 0)
    ret = A - B;
  else
    ret = B - A;
  if(abs(ret) >= 1e+18)
    cout << "Unfair" << endl;
  else
    cout << ret << endl;

  return 0;
}

