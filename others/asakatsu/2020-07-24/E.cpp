#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

vector<vector<pair<int, ll>>> G;
vector<int> Tpl;
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(auto ele: G[cur]) dfs(ele.first);
  Tpl.push_back(cur);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  G = vector<vector<pair<int, ll>>>(n);
  vis = vector<bool>(n);
  rep(i, m) {
    int l, r; ll d; cin >> l >> r >> d;
    l--; r--;
    G[l].push_back({r, d});
  }
  rep(i, n) dfs(i);
  reverse(all(Tpl));
  vector<ll> D(n, -1);
  D[Tpl[0]] = 0;
  for(int i: Tpl) {
    if(D[i]==-1) {
      for(auto ele: G[i]) {
        int ne = ele.first;
        ll d = ele.second;
        if(D[ne]==-1) continue;
        D[i] = D[ne]-d;
      }
    }
    if(D[i]==-1) D[i] = 0;
    for(auto ele: G[i]) {
      int ne = ele.first;
      ll d = ele.second;
      if(D[ne]==-1 || D[ne]==D[i]+d) D[ne] = D[i]+d;
      else {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}
