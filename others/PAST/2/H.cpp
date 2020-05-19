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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

int N;
int H, W;
vector<vector<edge>> G;
vector<ll> d;
vector<int> par;
void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;

    for (int i=0; i<(int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
	d[e.to] = d[v] + e.cost;
	que.push(P(d[e.to], e.to));
	par[e.to] = v;
      }
    }
  }
}
int pos2int(pair<int, int>& p) {
  return p.first*W+p.second;
}
int dis(pair<int, int>& p1, pair<int, int>& p2) {
  return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}
int main() {
  cin >> H >> W;
  N = H * W;
  vector<vector<char>> A(H, vector<char>(W));
  G = vector<vector<edge>>(N);
  vector<vector<pair<int, int>>> ve(11);
  rep(i, H) rep(j, W) {
    cin >> A[i][j];
    int id;
    if(A[i][j] == 'S') id = 0;
    else if(A[i][j] == 'G') id = 10;
    else id = int(A[i][j]-'0');
    ve[id].emplace_back(i, j);
  }
  REP(i, 1, 11) {
    for(auto from: ve[i-1]) {
      for(auto to: ve[i]) {
        G[pos2int(from)].emplace_back(pos2int(to), dis(from, to));
      }
    }
  }
  dijkstra(pos2int(ve[0][0]));
  cout << (d[pos2int(ve[10][0])]==longinf ? -1 : d[pos2int(ve[10][0])]) << endl;
  return 0;
}
