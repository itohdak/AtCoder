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
  int h, w, k; cin >> h >> w >> k;
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  sx--; sy--; tx--; ty--;
  vector<string> S(h);
  rep(i, h) cin >> S[i];
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<ll> cost(h*w*4, longinf);
  vector<bool> vis(h*w*4);
  auto toId = [&](int x, int y, int d) {
    return (x*w+y)*4+d;
  };
  rep(i, 4) {
    cost[toId(sx, sy, i)] = 0;
    q.push({0, toId(sx, sy, i)});
  }
  while(!q.empty()) {
    auto ele = q.top(); q.pop();
    int tmp = ele.second;
    int x = tmp/4/w;
    int y = tmp/4%w;
    int d = tmp%4;
    if(cost[tmp] != ele.first) continue;
    if(vis[tmp]) continue;
    vis[tmp] = true;
    rep(i, 4) {
      if(i == d) continue;
      int ne = toId(x, y, i);
      if((cost[tmp]+k-1)/k*k < cost[ne]) {
        cost[ne] = (cost[tmp]+k-1)/k*k;
        q.push({cost[ne], ne});
      }
    }
    {
      int nx = x+dx[d];
      int ny = y+dy[d];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '@') continue;
      int ne = toId(nx, ny, d);
      if(cost[tmp]+1 < cost[ne]) {
        cost[ne] = cost[tmp]+1;
        q.push({cost[ne], ne});
      }
    }
  }
  ll ans = longinf;
  rep(i, 4) ans = min(cost[toId(tx, ty, i)], ans);
  cout << (ans==longinf ? -1 : (ans+k-1)/k) << "\n";
  return 0;
}
