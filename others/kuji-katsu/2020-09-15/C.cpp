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
  int n; cin >> n;
  string s; cin >> s;
  vector<vector<int>> cnt(3, vector<int>(n+1));
  rep(i, n) {
    rep(j, 3) cnt[j][i+1] = cnt[j][i];
    if(s[i] == 'R') {
      cnt[0][i+1]++;
    } else if(s[i] == 'G') {
      cnt[1][i+1]++;
    } else {
      cnt[2][i+1]++;
    }
  }
  ll ans = 0;
  rep(i, n) REP(j, i+1, n) {
    if(s[i] == s[j]) continue;
    if(s[i] != 'R' && s[j] != 'R') {
      ans += cnt[0][n] - cnt[0][j+1] - (2*j-i < n && s[2*j-i] == 'R');
    } else if(s[i] != 'G' && s[j] != 'G') {
      ans += cnt[1][n] - cnt[1][j+1] - (2*j-i < n && s[2*j-i] == 'G');
    } else if(s[i] != 'B' && s[j] != 'B') {
      ans += cnt[2][n] - cnt[2][j+1] - (2*j-i < n && s[2*j-i] == 'B');
    }
  }
  cout << ans << endk;
  return 0;
}
