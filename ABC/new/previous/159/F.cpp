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
const ll mod = 998244353;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  vector<vector<vector<ll> > > dp(N+1, vector<vector<ll> >(S+1, vector<ll>(3)));
  dp[0][0][0] = 1;
  rep(i, N) {
    rep(s, S+1) {
      (dp[i+1][s][0] += dp[i][s][0]) %= mod;
      (dp[i+1][s][1] += dp[i][s][1] + dp[i][s][0]) %= mod;
      (dp[i+1][s][2] += dp[i][s][2] + dp[i][s][1] + dp[i][s][0]) %= mod;
      if(s+A[i] < S+1) {
	(dp[i+1][s+A[i]][1] += dp[i][s][0] + dp[i][s][1]) %= mod;
	(dp[i+1][s+A[i]][2] += dp[i][s][0] + dp[i][s][1]) %= mod;
      }
    }
  }
  cout << dp[N][S][2] << endl;
  return 0;
}

