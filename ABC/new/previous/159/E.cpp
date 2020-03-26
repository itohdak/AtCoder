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
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  rep(i, H) cin >> S[i];
  int ans_min = inf;
  rep(t, 1<<H) {
    // prepare
    map<int, int> idx;
    int ngroup = 1;
    rep(i, H) {
      idx[i] = ngroup-1;
      if((t>>i)&1) ngroup++;
    }
    vector<vector<int> > cnt(ngroup, vector<int>(W+1));
    rep(i, H) rep(j, W) {
      if(S[i][j] == '1') cnt[idx[i]][j+1]++;
    }
    bool ok = true;
    rep(i, ngroup) rep(j, W+1) {
      if(cnt[i][j] > K) ok = false;
      if(j) cnt[i][j] = cnt[i][j] + cnt[i][j-1];
    }
    if(!ok) continue;
    // cout << cnt << endl;
    // prepare end
    int prev = 0;
    int ans = 0;
    vector<char> cut(W, '0');
    rep(j, W+1) {
      bool cutp = false;
      rep(i, ngroup) {
	if(cnt[i][j] - cnt[i][prev] > K) cutp = true;
      }
      if(cutp) {
	ans++;
	prev = j-1;
	cut[j-1] = '1';
      }
    }
    if(ans+ngroup-1 < ans_min) {
      ans_min = ans + ngroup-1;
      // cout << cut << endl;
      // cout << t << endl;
    }
  }
  cout << ans_min << endl;
  return 0;
}

