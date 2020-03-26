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
vector<ll> D;

int main() {
  int N;
  cin >> N;
  G = vector<vector<edge> >(N);
  D = vector<ll>(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(edge(b, 1));
    G[b].push_back(edge(a, 1));
  }
  int M;
  cin >> M;
  vector<int> U(M), V(M);
  rep(i, M) cin >> U[i] >> V[i];
  return 0;
}

