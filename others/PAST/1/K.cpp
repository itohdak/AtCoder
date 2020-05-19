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

int in[200000], out[200000];
int cnt = -1;
vector<vector<int>> G;
void dfs(int tmp, int par) {
  cnt++;
  in[tmp] = cnt;
  for(int ne: G[tmp]) if(ne != par) dfs(ne, tmp);
  out[tmp] = cnt;
}
int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  int pres;
  G = vector<vector<int>>(N);
  rep(i, N) {
    cin >> P[i];
    if(P[i] == -1) pres = i;
    else {
      P[i]--;
      G[P[i]].push_back(i);
    }
  }
  dfs(pres, -1);
  int Q;
  cin >> Q;
  rep(q, Q) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if(in[b] <= in[a] && out[a] <= out[b]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
