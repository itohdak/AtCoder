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
int dfs(int tmp, int par) {
  if(G[tmp].size() == 0) return 1;
  multiset<int, greater<int>> se, se2;
  for(int ne: G[tmp]) se.insert(dfs(ne, tmp));
  auto itr = se.begin();
  rep(i, se.size()) {
    se2.insert(*itr+i);
    itr++;
  }
  // cout << tmp << ' ' << *se2.begin() << endl;
  return *se2.begin()+(par!=-1);
}
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  G = vector<vector<int>>(N);
  A[0] = -1;
  REP(i, 1, N) {
    cin >> A[i];
    A[i]--;
    G[A[i]].push_back(i);
  }
  cout << dfs(0, -1) << endl;
  return 0;
}
