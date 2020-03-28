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

#define MAX_N 200005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}

ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}

vector<vector<edge> > G;
vector<ll> D;
vector<int> size;
int dfsSize(int tmp, int par) {
  size[tmp] = 1;
  for(auto ne: G[tmp])
    if(ne.to != par)
      size[tmp] += dfsSize(ne.to, tmp);
  return size[tmp];
}
ll dfs(int tmp, int par) {
  ll dp = 1;
  for(auto ne: G[tmp])
    if(ne.to != par)
      (((dp *= dfs(ne.to, tmp)) %= mod) *= finv[size[ne.to]]) %= mod;
  D[tmp] = dp * fac[size[tmp]-1] % mod;
  return D[tmp];
}
vector<ll> ans;
int N;
void dfs2(int tmp, int par, ll d_par) {
  ll dp = 1;
  for(auto ne: G[tmp]) {
    if(ne.to != par)
      (((dp *= D[ne.to]) %= mod) *= finv[size[ne.to]]) %= mod;
    else {
      (((dp *= d_par) %= mod) *= finv[N-size[tmp]]) %= mod;
    }
  }
  ans[tmp] = dp * fac[N-1] % mod;

  for(auto ne: G[tmp])
    if(ne.to != par) {
      ll next_d_par = ((dp * fac[size[ne.to]] % mod) * modinv(D[ne.to]) % mod) * fac[N-size[ne.to]-1] % mod;
      dfs2(ne.to, tmp, next_d_par);
    }
}

int main() {
  make();
  cin >> N;
  G = vector<vector<edge> >(N);
  D = vector<ll>(N);
  size = vector<int>(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(edge(b, 1));
    G[b].push_back(edge(a, 1));
  }
  dfsSize(0, -1);
  dfs(0, -1);
  ans = vector<ll>(N);
  dfs2(0, -1, 0);
  rep(i, N) cout << ans[i] << endl;
  return 0;
}

