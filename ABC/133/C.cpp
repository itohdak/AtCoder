#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  ll L, R;
  cin >> L >> R;
  if(L % 2019 == 0 || R % 2019 == 0)
    cout << 0 << endl;
  else if(L / 2019 < R / 2019)
    cout << 0 << endl;
  else {
    int l = L % 2019;
    int r = R % 2019;
    int ans = 2020;
    REP(i, l, r+1) {
      REP(j, i+1, r+1) {
        ans = min(ans, (i * j) % 2019);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

