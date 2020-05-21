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
  vector<pair<int, pair<int, int>>> YAB(M);
  rep(i, M) {
    cin >> YAB[i].second.first >> YAB[i].second.second >> YAB[i].first;
    --YAB[i].second.first;
    --YAB[i].second.second;
  }
  sort(all(YAB), greater<pair<int, pair<int, int>>>());
  int Q;
  cin >> Q;
  vector<pair<int, int>> WV(Q);
  vector<int> id(Q), ans(Q);
  rep(i, Q) {
    cin >> WV[i].second >> WV[i].first;
    --WV[i].second;
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) { return WV[i] > WV[j]; } );
  UnionFind uf(N);
  int tmp = 0;
  rep(i, Q) {
    while(tmp < M && YAB[tmp].first > WV[id[i]].first) {
      uf.unite(YAB[tmp].second.first, YAB[tmp].second.second);
      tmp++;
    }
    ans[id[i]] = uf.nGroup[uf.root(WV[id[i]].second)];
  }
  rep(i, Q) cout << ans[i] << endl;
  return 0;
}
