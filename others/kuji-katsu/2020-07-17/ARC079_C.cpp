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
  int n, m; cin >> n >> m;
  vector<set<int>> G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  for(int i: G[0]) {
    if(G[n-1].count(i)) {
      cout << "POSSIBLE" << "\n";
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << "\n";
  return 0;
}
