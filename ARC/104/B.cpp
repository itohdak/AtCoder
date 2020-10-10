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
  vector<vector<int>> cnt(4, vector<int>(n+1));
  map<char, int> mp = {{'A', 0}, {'T', 1}, {'C', 2}, {'G', 3}};
  rep(i, n) {
    rep(j, 4) cnt[j][i+1] += cnt[j][i];
    cnt[mp[s[i]]][i+1]++;
  }
  int ans = 0;
  rep(i, n+1) rep(j, i) {
    vector<int> cnt2(4);
    rep(k, 4) cnt2[k] = cnt[k][i]-cnt[k][j];
    if(cnt2[0] == cnt2[1] && cnt2[2] == cnt2[3]) ans++;
  }
  cout << ans << endk;
  return 0;
}
