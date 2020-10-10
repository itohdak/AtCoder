#include <bits/stdc++.h>
#include <print.hpp>
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<string> ans(h, string(w, ' '));
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') {
      ans[i][j] = '#';
      continue;
    }
    int cnt = 0;
    for(int dx=-1; dx<=1; dx++) {
      for(int dy=-1; dy<=1; dy++) {
        if(dx == 0 && dy == 0) continue;
        int x = i + dx;
        int y = j + dy;
        if(x < 0 || x >= h || y < 0 || y >= w) continue;
        if(S[x][y] == '#') cnt++;
      }
    }
    ans[i][j] = char('0'+cnt);
  }
  rep(i, h) cout << ans[i] << endk;
  return 0;
}
