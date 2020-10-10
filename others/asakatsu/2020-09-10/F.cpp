#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/templates/print.hpp"
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, s; cin >> n >> m >> s;
  s--;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  priority_queue<pair<int, int>> q;
  vector<int> d(n, 0);
  d[s] = s;
  q.push({s, s});
  while(!q.empty()) {
    auto p = q.top(); q.pop();
    int cur = p.second;
    if(d[cur] != p.first) continue;
    for(auto ne: G[cur]) {
      if(d[ne] < min(d[cur], ne)) {
        d[ne] = min(d[cur], ne);
        q.push({d[ne], ne});
      }
    }
  }
  rep(i, n) if(d[i] == i) cout << i+1 << endk;
  return 0;
}
