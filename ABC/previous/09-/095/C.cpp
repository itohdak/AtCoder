#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, C;
  ll X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ret = 0;
  ll tmp = min(X, Y);
  ret += min(A + B, C * 2) * tmp;
  ret += (X - tmp) * min(A, C * 2) + (Y - tmp) * min(B, C * 2);
  cout << ret << endl;
  return 0;
}

