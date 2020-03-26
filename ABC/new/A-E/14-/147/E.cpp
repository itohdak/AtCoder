#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
// template<class t, class u>
// ostream& operator<<(ostream& os, const pair<t, u>& p) {
//   return os << "{" << p.first << ", " << p.second << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
//   os << "{";
//   rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
//   return os << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const set<t>& se) {
//   os << "{";
//   auto itr = se.begin();
//   rep(i, se.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
// template<class t, class u>
// ostream& operator<<(ostream& os, const map<t, u>& mp) {
//   os << "{";
//   auto itr = mp.begin();
//   rep(i, mp.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> >
    A(H, vector<int>(W)),
    B(H, vector<int>(W)),
    C(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> A[i][j];
  rep(i, H) rep(j, W) cin >> B[i][j];
  rep(i, H) rep(j, W) C[i][j] = abs(A[i][j] - B[i][j]);
  int N = 80*80*2;
  vector<vector<vector<bool> > > dp(H, vector<vector<bool> >(W, vector<bool>(N*2)));
  int sub = C[0][0];
  dp[0][0][sub+N] = true;
  dp[0][0][-sub+N] = true;
  rep(i, H) rep(j, W) {
    rep(k, N*2) {
      if(i+1 < H) {
        if(k+C[i+1][j] >= 0 && k+C[i+1][j] < N*2)
          dp[i+1][j][k+C[i+1][j]] = dp[i+1][j][k+C[i+1][j]] | dp[i][j][k];
        if(k-C[i+1][j] >= 0 && k-C[i+1][j] < N*2)
          dp[i+1][j][k-C[i+1][j]] = dp[i+1][j][k-C[i+1][j]] | dp[i][j][k];
      }
      if(j+1 < W) {
        if(k+C[i][j+1] >= 0 && k+C[i][j+1] < N*2)
          dp[i][j+1][k+C[i][j+1]] = dp[i][j+1][k+C[i][j+1]] | dp[i][j][k];
        if(k-C[i][j+1] >= 0 && k-C[i][j+1] < N*2)
          dp[i][j+1][k-C[i][j+1]] = dp[i][j+1][k-C[i][j+1]] | dp[i][j][k];
      }
    }
  }
  int ans = inf;
  rep(i, N*2)
    if(dp[H-1][W-1][i]) ans = min(ans, abs(i-N));
  cout << ans << endl;
  return 0;
}

