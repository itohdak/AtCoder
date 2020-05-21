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
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> vis(N);
  set<int> se;
  se.insert(0);
  vector<int> ans(N);
  rep(i, N) {
    int mn = *se.begin();
    se.erase(mn);
    ans[i] = mn;
    vis[mn] = true;
    for(int ne: G[mn]) if(!vis[ne]) se.insert(ne);
  }
  rep(i, N) {
    if(i) cout << ' ';
    cout << ans[i]+1;
  }
  cout << endl;
  return 0;
}
