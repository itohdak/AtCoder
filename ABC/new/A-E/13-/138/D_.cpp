#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void dfs(vector<vector<int> >& G, vector<ll>& P, int tmp, int par) {
  if(par != -1)
    P[tmp] += P[par];
  for(auto ne: G[tmp]) {
    if(ne != par)
      dfs(G, P, ne, tmp);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int> > G(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<ll> P(N);
  rep(i, Q) {
    int p, x;
    cin >> p >> x;
    p--;
    P[p] += x;
  }
  dfs(G, P, 0, -1);
  rep(i, N)
    cout << P[i] << ' ';
  cout << endl;
  return 0;
}

