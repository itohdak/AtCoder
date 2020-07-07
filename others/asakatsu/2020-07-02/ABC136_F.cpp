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
  int M;
  ll K;
  cin >> M >> K;
  if(K == 0) {
    rep(i, 1<<M) cout << i << ' ' << i << ' ';
    cout << "\n";
  } else {
    ll xorall = 0;
    rep(i, 1<<M) xorall ^= i;
    rep(j, 1<<M) {
      if(K == j && K == (xorall^j)) {
        rep(i, 1<<M) if(i!=j) cout << i << ' ';
        cout << j << ' ';
        rrep(i, (1<<M)) if(i!=j) cout << i << ' ';
        cout << j << ' ';
        cout << "\n";
        return 0;
      }
    }
    cout << -1 << "\n";
  }
  return 0;
}
