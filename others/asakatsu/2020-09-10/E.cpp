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
  int r, c, K; cin >> r >> c >> K;
  vector<string> S(r); rep(i, r) cin >> S[i];
  vector<vector<vector<int>>> cnt(2, vector<vector<int>>(r, vector<int>(c)));
  rep(j, c) {
    int tmp = 0;
    rep(i, r) {
      if(S[i][j] == 'x') tmp = 0;
      else tmp++;
      cnt[0][i][j] = tmp;
    }
  }
  rep(j, c) {
    int tmp = 0;
    rrep(i, r) {
      if(S[i][j] == 'x') tmp = 0;
      else tmp++;
      cnt[1][i][j] = tmp;
    }
  }
  int ans = 0;
  rep(i, r) rep(j, c) {
    if(j-K+1 < 0 || j+K > c) continue;
    bool ok = true;
    for(int k=j-K+1; k<j+K; k++) {
      if(cnt[0][i][k] < K-abs(k-j) || cnt[1][i][k] < K-abs(k-j)) ok = false;
    }
    if(ok) ans++;
  }
  cout << ans << endk;
  return 0;
}
