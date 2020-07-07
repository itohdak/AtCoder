#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  int s = 0;
  rep(i, H) {
    cin >> S[i];
    rep(j, W) if(S[i][j] == 'S') s = i*W+j;
  }
  vector<int> d(H*W);
  vector<bool> vis(H*W);
  set<int> se;
  auto bfs = [&]() {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      int x = cur/W;
      int y = cur%W;
      if(vis[cur]) continue;
      vis[cur] = true;
      se.insert(cur);
      rep(k, 4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(S[nx][ny] == '#') continue;
        int ne = nx*W+ny;
        if(vis[ne]) continue;
        if(d[cur]>=K) continue;
        d[ne] = d[cur]+1;
        q.push(ne);
      }
    }
  };
  bfs();
  int ans = inf;
  for(auto s: se) {
    int x = s/W;
    int y = s%W;
    int mn = min({x, y, H-1-x, W-1-y});
    ans = min((mn+K-1)/K+1, ans);
  }
  cout << ans << "\n";
  return 0;
}
