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

vector<vector<pair<int, int> > > E; // edges
vector<int> col;
void dfs(int tmp, int par, int par_i) {
  int color = 1;
  int par_col;
  if(par == -1) par_col = -1;
  else par_col = col[par_i];
  for(auto c: E[tmp]) {
    if(c.first != par) {
      if(color == par_col) color++;
      col[c.second] = color;
      color++;
      dfs(c.first, tmp, c.second);
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  E = vector<vector<pair<int, int> > >(N);
  col = vector<int>(N-1, 0);
  rep(i, N-1) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    E[A[i]].push_back(make_pair(B[i], i));
    E[B[i]].push_back(make_pair(A[i], i));
  }
  int ans = 0;
  rep(i, N) ans = max((int)E[i].size(), ans);
  dfs(0, -1, -1);
  cout << ans << endl;
  rep(i, N-1) cout << col[i] << endl;
  return 0;
}

