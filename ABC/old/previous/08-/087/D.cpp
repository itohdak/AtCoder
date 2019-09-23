#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct data {
  int to;
  ll d;
  data(int to_, ll d_) : to(to_), d(d_) {}
};

bool dfs(vector<ll>& G, vector<vector<data> >& A, vector<bool>& vis, int tmp, int par, ll d) {
  // cout << tmp << ' ' << par << ' ' << d << endl;
  if(par != -1) {
    if(G[tmp] == longinf)
      G[tmp] = G[par] + d;
    else if(G[tmp] - G[par] != d)
      return false;
  }
  if(!vis[tmp]) {
    vis[tmp] = true;
    for(auto ne: A[tmp])
      if(!dfs(G, A, vis, ne.to, tmp, ne.d))
        return false;
    return true;
  } else {
    return true;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<data> > A(N);
  rep(i, M) {
    int l, r, d;
    cin >> l >> r >> d;
    l--; r--;
    A[l].push_back(data(r, d));
    A[r].push_back(data(l, -d));
  }
  vector<ll> G(N, longinf);
  vector<bool> vis(N);
  bool res = true;
  rep(i, N) {
    if(!vis[i]) {
      G[i] = 0;
      if(!res) break;
      res &= dfs(G, A, vis, i, -1, 0);
    }
  }
  if(res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

