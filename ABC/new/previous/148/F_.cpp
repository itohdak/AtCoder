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

struct edge {
  int to;
  ll cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

vector<vector<edge> > G;
vector<ll> Du, Dv;
set<int> leaves;
int N, u, v;
void dfs(int tmp, int par, ll cost, vector<ll>& D) {
  if(par != -1) {
    D[tmp] = D[par] + cost;
  }
  for(auto ne: G[tmp])
    if(ne.to != par)
      dfs(ne.to, tmp, ne.cost, D);
  if(G[tmp].size() == 1) leaves.insert(tmp);
}

int main() {
  cin >> N >> u >> v;
  u--; v--;
  G = vector<vector<edge> >(N);
  Du = vector<ll>(N);
  Dv = vector<ll>(N);
  vector<int> A(N-1), B(N-1);
  rep(i, N-1) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    G[A[i]].push_back(edge(B[i], 1));
    G[B[i]].push_back(edge(A[i], 1));
  }
  dfs(u, -1, 0, Du);
  dfs(v, -1, 0, Dv);
  ll ans = 0;
  for(int leaf: leaves) {
    if(Du[leaf] < Dv[leaf]) {
      ans = max(Dv[leaf]-1, ans);
    }
  }
  cout << ans << endl;
  return 0;
}

