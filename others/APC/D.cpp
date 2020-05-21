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

#define MAX_N 200005

class UnionFind
{
public:
  int par[MAX_N];
  int depth[MAX_N];
  int nGroup[MAX_N];

  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }

  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;

    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  UnionFind uf(N);
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    uf.unite(x, y);
  }
  int need = 2*(N-1-M);
  if(N < need) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<priority_queue<ll>> ve(N);
  rep(i, N) ve[uf.root(i)].push(A[i]);
  bool allSame = true;
  rep(i, N) if(!uf.same(i, 0)) allSame = false;
  if(allSame) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  priority_queue<ll> q;
  rep(i, N) {
    if(ve[i].empty()) continue;
    while(ve[i].size() > 1) {
      q.push(ve[i].top());
      ve[i].pop();
    }
    ans += ve[i].top();
    ve[i].pop();
  }
  rep(i, N-need) q.pop();
  while(!q.empty()) {
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
  return 0;
}
