#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<string> A(n), B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  bool ans = false;
  rep(i, n) rep(j, n) {
    if(i+m>n || j+m>n) continue;
    bool ok = true;
    rep(k, m) rep(l, m) {
      if(A[i+k][j+l] != B[k][l]) {
        ok = false;
        break;
      }
    }
    if(ok) {
      ans = true;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << "\n";
  return 0;
}
