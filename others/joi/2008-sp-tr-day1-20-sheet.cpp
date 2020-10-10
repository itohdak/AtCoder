#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

vector<vector<int>> G;
vector<int> Tpl;

/* topological sort */
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, w, h; cin >> n >> w >> h;
  vector<vector<int>> C(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> C[i][j];
  vector<int> mnX(n, inf), mnY(n, inf), mxX(n), mxY(n);
  rep(i, h) rep(j, w) {
    if(C[i][j] == 0) continue;
    chmin(mnX[C[i][j]-1], i);
    chmin(mnY[C[i][j]-1], j);
    chmax(mxX[C[i][j]-1], i);
    chmax(mxY[C[i][j]-1], j);
  }
  // cout << mnX << mxX << mnY << mxY << endk;
  G = vector<vector<int>>(n);
  vis = vector<bool>(n);
  rep(i, n) {
    for(int x=mnX[i]; x<=mxX[i]; x++) {
      for(int y=mnY[i]; y<=mxY[i]; y++) {
        if(C[x][y] != 0 && C[x][y] != i+1) {
          G[i].push_back(C[x][y]-1);
        }
      }
    }
  }
  rep(i, n) dfs(i);
  reverse(all(Tpl));
  rep(i, n) {
    if(i) cout << ' ';
    cout << Tpl[i]+1;
  }
  cout << endk;
  return 0;
}
