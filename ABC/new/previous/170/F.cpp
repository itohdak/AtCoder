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

using P = pair<ll, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H, W;
  ll K;
  cin >> H >> W >> K;
  vector<int> X(2), Y(2);
  rep(i, 2) {
    cin >> X[i] >> Y[i];
    X[i]--; Y[i]--;
  }
  vector<string> S(H);
  rep(i, H) cin >> S[i];

  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, -1, 0, 1};
  auto pos2int = [&](int x, int y, int v) {
    return (x * W + y) * 4 + v;
  };

  int N = H*W*4;
  priority_queue<P, vector<P>, greater<P>> q;
  vector<ll> dis(N, longinf);
  rep(k, 4) {
    int s = pos2int(X[0], Y[0], k);
    dis[s] = 0;
    q.push(P(0, s));
  }
  while(!q.empty()) {
    P p = q.top();
    q.pop();
    int v = p.second;
    if(dis[v] != p.first) continue;
    int x = v/W/4;
    int y = v/4%W;
    int d = v%4;
    rep(k, 4) {
      int ne = pos2int(x, y, k);
      if((dis[v]+K-1)/K*K < dis[ne]) {
        dis[ne] = (dis[v]+K-1)/K*K;
        q.push(P(dis[ne], ne));
      }
    }
    {
      int nx = x+dx[d];
      int ny = y+dy[d];
      if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if(S[nx][ny] == '@') continue;
      int ne = pos2int(nx, ny, d);
      if(dis[v]+1 < dis[ne]) {
        dis[ne] = dis[v]+1;
        q.push(P(dis[ne], ne));
      }
    }
  }
  // cout << dis << endl;
  ll ans = longinf;
  rep(k, 4) ans = min(dis[pos2int(X[1], Y[1], k)], ans);
  cout << (ans == longinf ? -1 : (ans+K-1)/K) << endl;
  return 0;
}
