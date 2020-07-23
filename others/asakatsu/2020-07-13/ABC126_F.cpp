#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m; ll k; cin >> m >> k;
  if(k == 0) {
    rep(i, 1<<m) cout << i << ' ' << i << ' ';
    cout << "\n";
  } else if(k >= (1<<m)) {
    cout << -1 << "\n";
  } else {
    ll x = 0;
    rep(i, 1<<m) if(i != k) x ^= i;
    if(x == k) {
      rep(i, 1<<m) if(i != k) cout << i << ' ';
      cout << k << ' ';
      rrep(i, (1<<m)) if(i != k) cout << i << ' ';
      cout << k << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
