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

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N), B(N), C(N), D(M), E(M), F(M);
  map<ll, ll> mpX, mpY; // 座標圧縮のための座標
  mpX[0] = 0;
  mpY[0] = 0;
  rep(i, N) {
    cin >> A[i] >> B[i] >> C[i];
    mpX[A[i]] = 0;
    mpX[B[i]] = 0;
    mpY[C[i]] = 0;
  }
  rep(i, M) {
    cin >> D[i] >> E[i] >> F[i];
    mpX[D[i]] = 0;
    mpY[E[i]] = 0;
    mpY[F[i]] = 0;
  }
  /* 座標圧縮 mpX[] */
  vector<int> xs, ys;
  for(auto& p: mpX) {
    p.second = xs.size();
    xs.push_back(p.first);
  }
  for(auto& p: mpY) {
    p.second = ys.size();
    ys.push_back(p.first);
  }
  int H = xs.size()*2;
  int W = ys.size()*2;
  vector<vector<int>> dis(H, vector<int>(W));
  rep(i, N) {
    ll a = mpX[A[i]]*2;
    ll b = mpX[B[i]]*2;
    ll c = mpY[C[i]]*2;
    for(ll x=a; x<=b; x++) dis[x][c] = -1;
  }
  rep(i, M) {
    ll d = mpX[D[i]]*2;
    ll e = mpY[E[i]]*2;
    ll f = mpY[F[i]]*2;
    for(ll y=e; y<=f; y++) dis[d][y] = -1;
  }
  int dx[] = {0, -1, 0, 1};
  int dy[] = {-1, 0, 1, 0};
  queue<pair<ll, ll>> Q;
  ll sx = mpX[0]*2;
  ll sy = mpY[0]*2;
  Q.emplace(sx, sy);
  while(!Q.empty()) {
    auto p = Q.front();
    Q.pop();
    if(dis[p.first][p.second] != 0) continue;
    dis[p.first][p.second] = 1;
    rep(k, 4) {
      ll nx = p.first  + dx[k];
      ll ny = p.second + dy[k];
      if(nx < 0 || nx >= H) continue;
      if(ny < 0 || ny >= W) continue;
      Q.emplace(nx, ny);
    }
  }

  ll ans = 0;
  rep(x, H) rep(y, W) {
    if(dis[x][y] != 1) continue;
    if(x == 0 || x == H-1 || y == 0 || y == W-1) {
      cout << "INF" << endl;
      return 0;
    }
    if(x%2==0 || y%2==0) continue;
    ans += (xs[x/2+1]-xs[x/2]) * (ys[y/2+1]-ys[y/2]);
  }
  cout << ans << endl;
  return 0;
}
