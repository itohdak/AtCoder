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
  vector<string> A(H);
  rep(i, H) cin >> A[i];
  int s = -1;
  rep(i, H) rep(j, W) if(A[i][j] == 'S') s = i*W+j;
  int dx[] = {0, -1, 0, 1};
  int dy[] = {-1, 0, 1, 0};
  vector<int> dist(H*W);
  vector<int> S;
  auto bfs = [&]() {
    queue<int> q;
    q.push(s);
    vector<int> vis(H*W);
    while(!q.empty()) {
      int cur = q.front();
      q.pop();
      if(vis[cur]) continue;
      S.push_back(cur);
      vis[cur] = true;
      int x = cur/W;
      int y = cur%W;
      rep(k, 4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        int ne = nx*W+ny;
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(vis[ne]) continue;
        if(A[nx][ny] == '#') continue;
        if(dist[cur]+1 > K) continue;
        dist[ne] = dist[cur]+1;
        q.push(ne);
      }
    }
  };
  bfs();
  int ans = inf;
  for(int s: S) {
    int x = s/W;
    int y = s%W;
    ans = min((min({x, y, H-1-x, W-1-y})+K-1)/K, ans);
  }
  cout << ans+1 << endl;
  return 0;
}
