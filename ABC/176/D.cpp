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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> d;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  int ch, dh, cw, dw;
  cin >> ch >> cw >> dh >> dw;
  ch--; dh--; cw--; dw--;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<vector<edge>> G(h*w);
  rep(i, h) rep(j, w) {
    if(S[i][j] == '.') {
      for(int di=-2; di<=2; di++) {
        for(int dj=-2; dj<=2; dj++) {
          if(di==0 && dj==0) continue;
          int nx = i+di, ny = j+dj;
          if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if(S[nx][ny] == '#') continue;
          if(abs(di)+abs(dj)==1) {
            G[i*w+j].push_back({nx*w+ny, 0});
          } else {
            G[i*w+j].push_back({nx*w+ny, 1});
          }
        }
      }
    }
  }
  dijkstra(ch*w+cw, h*w, G);
  // cout << ch*w+cw << endk;
  // rep(i, h) {
  //   rep(j, w) {
  //     cout << d[i*w+j] << ' ';
  //   }
  //   cout << endk;
  // }
  cout << (d[dh*w+dw]==longinf ? -1LL : d[dh*w+dw]) << endk;
  return 0;
}
