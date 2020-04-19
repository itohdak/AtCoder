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

vector<vector<int>> to, from;
deque<int> L;
vector<bool> vis;
void dfs(int tmp) {
  if(!vis[tmp]) {
    vis[tmp] = 1;
    for(int ne: to[tmp]) dfs(ne);
    L.push_front(tmp);
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  to = vector<vector<int>>(N);
  from = vector<vector<int>>(N);
  vis = vector<bool>(N);
  rep(i, N-1+M) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    from[b].push_back(a);
  }
  int root = -1;
  rep(i, N) if(from[i].empty()) root = i;
  dfs(root);
  vector<int> new_num(N);
  int n = L.size();
  rep(i, n) {
    new_num[L.front()] = i;
    L.pop_front();
  }
  rep(i, N) {
    int par = -1;
    for(int j: from[i]) {
      if(new_num[j] > (par == -1 ? -1 : new_num[par])) {
	par = j;
      }
    }
    cout << par+1 << endl;
  }
  return 0;
}
