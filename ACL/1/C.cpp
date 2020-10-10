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
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  int n = h*w;
  mcf_graph<int, ll> G(n+2);
  auto id = [&](int i, int j) {
    return i*w+j;
  };
  int s = n, t = n+1;
  ll ans = 0;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    int cur = id(i, j);
    if(S[i][j] == 'o') {
      G.add_edge(s, cur, 1, 0);
      ans += (h-i-1) + (w-j-1);
    }
    G.add_edge(cur, t, 1, (h-i-1) + (w-j-1));
    if(i+1 < h && S[i+1][j] != '#') G.add_edge(cur, id(i+1, j), 100, 0);
    if(j+1 < w && S[i][j+1] != '#') G.add_edge(cur, id(i, j+1), 100, 0);
  }
  auto ret = G.flow(s, t);
  ans -= ret.second;
  cout << ans << endk;
  return 0;
}
