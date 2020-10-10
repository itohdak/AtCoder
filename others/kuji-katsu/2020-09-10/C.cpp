#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/templates/print.hpp"
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> S(m), C(m);
  vector<int> d(n, -1);
  rep(i, m) {
    cin >> S[i] >> C[i];
    S[i]--;
  }
  rep(i, m) {
    if(d[S[i]] != -1 && d[S[i]] != C[i]) {
      cout << -1 << endk;
      return 0;
    } else {
      d[S[i]] = C[i];
    }
  }
  if(n == 1) {
    if(d[0] == -1) cout << 0 << endk;
    else cout << d[0] << endk;
  } else {
    if(d[0] == 0) cout << -1 << endk;
    else {
      if(d[0] == -1) d[0] = 1;
      ll ans = 0;
      rep(i, n) {
        if(d[i] != -1) ans += pow(10, n-1-i) * d[i];
      }
      cout << ans << endk;
    }
  }
  return 0;
}
