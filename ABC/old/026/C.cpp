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
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  rep(i, N) {
    if(i == 0) continue;
    int b;
    cin >> b;
    b--;
    G[b].push_back(i);
  }
  function<int(int, int)> dfs = [&](int tmp, int par) {
    if(G[tmp].empty()) return 1;
    int mx = 0;
    int mn = inf;
    for(int ne: G[tmp]) {
      int ret = dfs(ne, tmp);
      mx = max(ret, mx);
      mn = min(ret, mn);
    }
    return mx + mn + 1;
  };
  cout << dfs(0, -1) << endl;
  return 0;
}
