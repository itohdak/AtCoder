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
  int N, X;
  cin >> N >> X;
  --X;
  vector<ll> H(N);
  rep(i, N) cin >> H[i];
  vector<vector<int>> G(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  function<int(int, int)> dfs = [&](int tmp, int par) {
    int ret = 0;
    for(int ne: G[tmp]) {
      if(ne != par) {
        ret += dfs(ne, tmp);
      }
    }
    if(ret || H[tmp]) return ret+2;
    else              return ret;
  };
  cout << max(dfs(X, -1)-2, 0) << endl;
  return 0;
}
