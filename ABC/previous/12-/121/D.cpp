#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll A, B;
  cin >> A >> B;
  ll sub = B - A + 1;
  ll ans = 0LL;
  ll pwr = 1LL;
  for(int i=0; i<=50; i++) {
    ll tmp = 0LL;
    ll a, b;
    sub /= 2;

    tmp += sub * pwr;

    a = A % (2 * pwr);
    b = (B + 1) % (2 * pwr);
    if(a < b) {
      tmp += max(b, pwr) - max(a, pwr);
    } else if(a > b){
      tmp += (max(b, pwr) - pwr) + ((2 * pwr) - max(a, pwr));
    }
    // cout << i << ' ' << tmp << endl;
    ans += pwr * (tmp % 2);

    pwr *= 2;
  }

  cout << ans << endl;
  return 0;
}

