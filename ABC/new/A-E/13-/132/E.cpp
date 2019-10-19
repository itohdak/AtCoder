#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct edge {
  int from;
  int to;
  edge(int from, int to) : from(from), to(to) {}
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > G(3*N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(N+v);
    G[N+u].push_back(2*N+v);
    G[2*N+u].push_back(v);
  }
  int S, T;
  cin >> S >> T;
  S--, T--;
  vector<int> D(3*N, inf);
  vector<bool> vis(3*N);
  queue<edge> Q;
  Q.push(edge(-1, S));
  while(!Q.empty()) {
    auto ne = Q.front();
    Q.pop();
    if(!vis[ne.to]) {
      vis[ne.to] = true;
      D[ne.to] = ne.from != -1 ? D[ne.from]+1 : 0;
      for(auto to: G[ne.to])
        Q.push(edge(ne.to, to));
    }
  }
  cout << (D[T] == inf ? -1 : D[T] / 3) << endl;
  return 0;
}

