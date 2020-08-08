#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w, k; cin >> h >> w >> k;
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  sx--; sy--; tx--; ty--;
  vector<string> S(h); rep(i, h) cin >> S[i];
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<bool> vis(h*w*4);
  vector<ll> D(h*w*4, longinf);
  rep(k, 4) {
    int id = (sx*w+sy)*4+k;
    D[id] = 0;
    q.push({0, id});
  }
  while(!q.empty()) {
    auto ele = q.top(); q.pop();
    ll dist = ele.first;
    int id = ele.second;
    int x = id/4/w;
    int y = id/4%w;
    int d = id%4;
    if(vis[id]) continue;
    if(D[id] != dist) continue;
    vis[id] = true;
    rep(i, 4) {
      int ne = (x*w+y)*4+i;
      if(D[ne] > (dist+k-1)/k*k) {
        D[ne] = (dist+k-1)/k*k;
        q.push({D[ne], ne});
      }
    }
    {
      int nx = x+dx[d];
      int ny = y+dy[d];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '@') continue;
      int ne = (nx*w+ny)*4+d;
      if(D[ne] > dist+1) {
        D[ne] = dist+1;
        q.push({D[ne], ne});
      }
    }
  }
  ll mn = longinf;
  rep(i, 4) {
    int id = (tx*w+ty)*4+i;
    mn = min(D[id], mn);
  }
  cout << (mn == longinf ? -1 : (mn+k-1)/k) << "\n";
  return 0;
}
