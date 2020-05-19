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

vector<vector<int>> G;
vector<vector<ll>> cnt;
void dfs(int tmp, int par) {
  if(par != -1 && G[tmp].size() == 1) {
    // cnt[tmp][0] = 1;
    // cnt[tmp][1] = 1;
    return;
  }
  for(int ne: G[tmp]) {
    if(ne != par) {
      dfs(ne, tmp);
      (cnt[tmp][0] *= (cnt[ne][0] + cnt[ne][1])) %= mod;
      (cnt[tmp][1] *= cnt[ne][0]) %= mod;
    }
  }
}
int main() {
  int N;
  cin >> N;
  G = vector<vector<int>>(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cnt = vector<vector<ll>>(N, vector<ll>(2, 1));
  dfs(0, -1);
  // cout << cnt << endl;
  cout << (cnt[0][0] + cnt[0][1]) % mod << endl;
  return 0;
}
