#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll x=ceil(sqrt(N-1)); x>0; x--)
    if((N - x) % x == 0) {
      ll m = (N - x) / x;
      if(x < m)
	ans += m;
    }
  cout << ans << endl;
  return 0;
}

