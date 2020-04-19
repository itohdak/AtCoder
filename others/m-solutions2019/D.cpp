#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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

ll sum;
vector<vector<int>> G;
vector<int> C;
vector<int> ans;
int id;
void dfs(int tmp, int par) {
  ans[tmp] = C[id];
  id++;
  if(par != -1) sum += ans[tmp];
  for(int ne: G[tmp]) {
    if(ne != par) {
      dfs(ne, tmp);
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

  C = vector<int>(N);
  rep(i, N) cin >> C[i];
  sort(all(C), greater<int>());

  int root;
  rep(i, N) if(G[i].size() == 1) root = i;
  sum = 0;
  id = 0;
  ans = vector<int>(N);
  dfs(root, -1);
  cout << sum << endl;
  rep(i, N) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
