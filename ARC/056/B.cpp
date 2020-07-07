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
  int N, M, S;
  cin >> N >> M >> S;
  S--;
  vector<vector<int>> G(N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  priority_queue<pair<int, int>> q;
  vector<int> D(N);
  D[S] = inf;
  q.push({inf, S});
  while(!q.empty()) {
    auto p = q.top(); q.pop();
    int v = p.second;
    if(D[v] != p.first) continue;
    for(int ne: G[v]) {
      if(D[ne] < min(D[v], v)) {
        D[ne] = min(D[v], v);
        q.push({D[ne], ne});
      }
    }
  }
  rep(i, N) {
    if(D[i] > i) cout << i+1 << "\n";
  }
  return 0;
}
