#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
const ll longinf = 1e18;
const ll mod = 1e9+7;

struct edge {
  int to, a;
  ll b;
};
struct state {
  int node, s;
  ll dist;
  bool operator<(const state& R) const {
    return dist > R.dist;
  }
};
int main() {
  int N, M, S;
  cin >> N >> M >> S;
  vector<vector<edge>> G(N);
  rep(i, M) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    --u, --v;
    G[u].push_back({v, a, b});
    G[v].push_back({u, a, b});
  }
  vector<int> C(N), D(N);
  rep(i, N) cin >> C[i] >> D[i];
  int mx = 5001;

  // dijkstra
  priority_queue<state> Q;
  vector<vector<ll>> dp(N+1, vector<ll>(mx+1, longinf));
  S = min(S, mx);
  dp[0][S] = 0;
  Q.push({0, S, 0});
  while(!Q.empty()) {
    int cur, s;
    ll d;
    cur = Q.top().node;
    s   = Q.top().s;
    d   = Q.top().dist;
    Q.pop();
    if(dp[cur][s] < d) continue;
    int ns = min(mx, s+C[cur]);
    ll nd = d+D[cur];
    if(dp[cur][ns]>nd) {
      dp[cur][ns] = nd;
      Q.push({cur, ns, nd});
    }
    for(auto& e: G[cur]) {
      if(s<e.a) continue;
      int ne = e.to;
      int ns = s-e.a;
      ll nd = d+e.b;
      if(dp[ne][ns]>nd) {
	dp[ne][ns] = nd;
	Q.push({ne, ns, nd});
      }
    }
  }
  rep(i, N) if(i) cout << *min_element(dp[i].begin(), dp[i].end()) << endl;
  return 0;
}
