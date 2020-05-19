#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int H, W;
vector<vector<int>> to;
deque<int> L;
vector<bool> vis;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int tmp) {
  if(!vis[tmp]) {
    vis[tmp] = true;
    for(int ne: to[tmp]) dfs(ne);
    L.push_front(tmp);
  }
}
int pos2int(int x, int y) {
  return x * W + y;
}
int main() {
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  to = vector<vector<int>>(H*W);
  vis = vector<bool>(H*W);
  rep(i, H) rep(j, W) cin >> A[i][j];
  rep(i, H) rep(j, W) {
    rep(k, 4) {
      int nx = i+dx[k], ny = j+dy[k];
      if(0<=nx && nx<H && 0<=ny && ny<W &&
         A[i][j] < A[nx][ny]) {
        to[pos2int(i, j)].push_back(pos2int(nx, ny));
      }
    }
  }
  rep(i, H*W) dfs(i);
  vector<ll> cnt(H*W, 1);
  while(!L.empty()) {
    int tmp = L.front();
    L.pop_front();
    for(int ne: to[tmp]) (cnt[ne] += cnt[tmp]) %= mod;
  }
  ll ans = 0;
  for(int c: cnt) (ans += c) %= mod;
  cout << ans << endl;
  return 0;
}
