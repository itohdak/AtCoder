#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
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
  int N;
  cin >> N;
  vector<ll> X(N), Y(N);
  map<ll, vector<ll>> cntX, cntY;
  rep(i, N) {
    cin >> X[i] >> Y[i];
    cntX[X[i]].push_back(Y[i]);
    cntY[Y[i]].push_back(X[i]);
  }
  map<ll, int> idx, idy;
  {
    int i = 0;
    for(auto x: cntX) {
      idx[x.first] = i;
      i++;
    }
    i = 0;
    for(auto y: cntY) {
      idy[y.first] = i;
      i++;
    }
  }
  UnionFind uf(idy.size());
  for(auto x: cntX) {
    int two = 0;
    for(ll y: x.second) {
      if(cntY[y].size() > 1) two++;
    }
    if(two) {
      for(ll y: x.second) {
        uf.unite(idy[x.second[0]], idy[y]);
      }
    }
  }
  map<int, set<ll>> points;
  map<int, int> cnt;
  for(auto y: cntY) {
    for(ll x: y.second) {
      points[uf.root(idy[y.first])].insert(x);
      cnt[uf.root(idy[y.first])]++;
    }
  }
  ll ans = 0;
  for(auto p: points) {
    ans += (uf.nGroup[p.first] * p.second.size()) - cnt[p.first];
  }
  cout << ans << endl;
  return 0;
}
