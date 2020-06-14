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
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> depth(N);
  function<void(int, int)> dfs = [&](int tmp, int par) {
    if(par != -1) depth[tmp] = depth[par]+1;
    for(int ne: G[tmp]) {
      if(ne != par) dfs(ne, tmp);
    }
  };
  depth[0] = 0;
  dfs(0, -1);
  int i = max_element(all(depth)) - depth.begin();
  dfs(i, -1);
  int j = max_element(all(depth)) - depth.begin();
  cout << i+1 << ' ' << j+1 << endl;
  return 0;
}
