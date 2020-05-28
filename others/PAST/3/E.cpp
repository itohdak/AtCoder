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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> G(N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> C(N);
  rep(i, N) cin >> C[i];
  rep(q, Q) {
    int type;
    cin >> type;
    if(type == 1) {
      int x;
      cin >> x;
      --x;
      cout << C[x] << endl;
      for(int ne: G[x]) C[ne] = C[x];
    } else {
      int x, y;
      cin >> x >> y;
      --x;
      cout << C[x] << endl;
      C[x] = y;
    }
  }
  return 0;
}
