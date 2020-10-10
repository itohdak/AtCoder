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
  int n, m; cin >> n >> m;
  vector<string> S(n); rep(i, n) cin >> S[i];
  mf_graph<int> G(n*m+2);
  int s = n*m, t = n*m+1;
  rep(i, n) rep(j, m) {
    if((i+j)%2) G.add_edge(s, i*m+j, 1);
    else G.add_edge(i*m+j, t, 1);
  }
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, n) rep(j, m) {
    if(S[i][j] == '#') continue;
    if((i+j)%2 == 0) continue;
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(S[nx][ny] == '#') continue;
      G.add_edge(i*m+j, nx*m+ny, 1);
    }
  }
  cout << G.flow(s, t) << endk;
  vector<string> ans(n);
  rep(i, n) ans[i] = S[i];
  string arrow[] = {"^v", "><", "v^", "<>"};
  for(auto e: G.edges()) {
    if(e.flow == 1 && e.from != s && e.to != t) {
      int from = e.from;
      int to = e.to;
      int fx = from/m, fy = from%m;
      int tx = to/m, ty = to%m;
      rep(k, 4) {
        if(tx == fx + dx[k] && ty == fy + dy[k]) {
          ans[fx][fy] = arrow[k][0];
          ans[tx][ty] = arrow[k][1];
          break;
        }
      }
    }
  }
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
