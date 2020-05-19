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
int l;
int id;
void dfs(int tmp, int par, int depth) {
  if(par != -1 && G[tmp].size() == 1) {
    if(depth > l) {
      l = depth;
      id = tmp;
      return;
    }
  }
  for(int ne: G[tmp]) if(ne != par) dfs(ne, tmp, depth+1);
}
int main() {
  int N;
  cin >> N;
  G = vector<vector<int>>(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int root;
  rep(i, N) if(G[i].size() == 1) root = i;
  dfs(root, -1, 0);
  dfs(id, -1, 0);
  if(l%3==1) cout << "Second" << endl;
  else cout << "First" << endl;
  return 0;
}
