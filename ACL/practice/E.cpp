#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<vector<ll>> A(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];
  mcf_graph<ll, ll> G(n*2+2);
  int s = n*2, t = n*2+1;
  ll mx = 1e9;
  rep(i, n) G.add_edge(s, i, k, 0);
  rep(i, n) G.add_edge(i+n, t, k, 0);
  rep(i, n) rep(j, n) {
    G.add_edge(i, j+n, 1, mx-A[i][j]);
  }
  G.add_edge(s, t, n*k, mx);
  auto ret = G.flow(s, t, n*k);
  ll ans = -ret.second;
  vector<string> B(n, string(n, '.'));
  for(auto e: G.edges()) {
    if(! (e.from == s) ^ (e.to == t)) ans += e.flow * mx;
    if(e.from != s && e.to != t && e.flow) {
      B[e.from][e.to-n] = 'X';
    }
  }
  cout << ans << endk;
  rep(i, n) cout << B[i] << endk;
  return 0;
}
