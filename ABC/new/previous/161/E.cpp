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
  int N, K, C;
  string S;
  cin >> N >> K >> C >> S;
  vector<int> dp(N);
  rep(i, min(C+1, N)) {
    if(S[i] == 'o') dp[i] = 1;
    else if(i)      dp[i] = dp[i-1];
    else            dp[i] = 0;
  }
  REP(i, C+1, N) {
    if(S[i] == 'o') dp[i] = max(dp[i-C-1]+1, dp[i]);
    else            dp[i] = dp[i-1];
  }
  // cout << dp << endl;

  vector<int> dp2(N);
  RREP(i, N-1, max(0, N-C-1)) {
    if(S[i] == 'o') dp2[i] = 1;
    else if(i<N-1)  dp2[i] = dp2[i+1];
    else            dp2[i] = 0;
  }
  rrep(i, N-C-1) {
    if(S[i] == 'o') dp2[i] = max(dp2[i+C+1]+1, dp2[i]);
    else            dp2[i] = dp2[i+1];
  }
  // cout << dp2 << endl;

  map<int, int> cnt;
  rep(i, N) {
    int tmp = dp[i] + dp2[i];
    if(!cnt.count(tmp)) cnt[tmp] = 0;
  }
  rep(i, C) {
    int tmp = dp[i] + dp2[i];
    cnt[tmp]++;
  }
  rep(i, N) {
    if(i > C) {
      int rem = dp[i-C-1] + dp2[i-C-1];
      cnt[rem]--;
    }
    if(i < N-C) {
      int add = dp[i+C] + dp2[i+C];
      cnt[add]++;
    }
    int tmp = dp[i] + dp2[i];
    if(S[i] == 'o' && tmp == K+1 && cnt[tmp] == 1) cout << i+1 << endl;
  }
  return 0;
}

