#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
  vector<int> A(n);
  vector<vector<int>> cnt(n+1, vector<int>(m));
  rep(i, n) {
    cin >> A[i];
    A[i]--;
    cnt[i+1] = cnt[i];
    cnt[i+1][A[i]]++;
  }
  vector<int> dp(1<<m, inf);
  dp[0] = 0;
  rep(i, 1<<m) {
    int c = 0;
    rep(j, m) if((i>>j)&1) c += cnt[n][j];
    rep(j, m) {
      if((i>>j)&1) continue;
      int k = cnt[n][j];
      chmin(dp[i|(1<<j)], dp[i]+(k-(cnt[c+k][j]-cnt[c][j])));
    }
  }
  cout << dp[(1<<m)-1] << endk;
  return 0;
}
