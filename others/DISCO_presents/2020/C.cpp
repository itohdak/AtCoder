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
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
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
  vector<vector<int> > ans(H, vector<int>(W));
  int tmp = 1;
  vector<set<int> > cnt(H);
  rep(i, H) rep(j, W) if(S[i][j] == '#') cnt[i].insert(j+1);
  int pre = -1;
  vector<bool> done(H);
  rep(i, H) {
    if(cnt[i].size() == 0) {
      if(pre != -1) {
        rep(j, W) ans[i][j] = ans[pre][j];
        done[i] = true;
        pre = i;
      }
    } else {
      int prev = 0;
      for(int c: cnt[i]) {
        REP(j, prev, c) ans[i][j] = tmp;
        prev = c;
        tmp++;
      }
      tmp--;
      REP(j, prev, W) ans[i][j] = tmp;
      tmp++;
      pre = i;
      done[i] = true;
    }
  }
  pre = H-1;
  rrep(i, H) {
    if(!done[i]) {
      rep(j, W) ans[i][j] = ans[pre][j];
      done[i] = true;
    } else {
      pre = i;
    }
  }
  rep(i, H) {
    rep(j, W) cout << ans[i][j] << ' ';
    cout << endl;
  }
  return 0;
}

