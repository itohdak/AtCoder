#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

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
  int n, m; cin >> n >> m;
  UnionFind uf(n);
  map<int, vector<pair<int, int>>> mp;
  rep(i, m) {
    int a, b, y;
    cin >> a >> b >> y;
    a--; b--;
    mp[y].push_back({a, b});
  }
  int q; cin >> q;
  vector<pair<pair<int, int>, int>> V(q);
  rep(i, q) {
    cin >> V[i].first.second >> V[i].first.first;
    V[i].first.second--;
    V[i].second = i;
  }
  sort(all(V), greater<pair<pair<int, int>, int>>());
  // cout << mp << endk;
  // cout << V << endk;
  vector<int> ans(q);
  {
    int i = 0;
    for(auto itr=mp.rbegin(); itr!=mp.rend(); itr++) {
      while(i < q && V[i].first.first >= itr->first) {
        // cout << i << endk;
        ans[V[i].second] = uf.nGroup[uf.root(V[i].first.second)];
        i++;
      }
      for(auto& p: itr->second) uf.unite(p.first, p.second);
      // cout << "unite " << itr->first << endk;
    }
    while(i < q) {
      ans[V[i].second] = uf.nGroup[uf.root(V[i].first.second)];
      i++;
    }
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
