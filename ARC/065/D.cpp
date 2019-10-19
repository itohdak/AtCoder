#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
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
  int N, K, L;
  cin >> N >> K >> L;
  vector<int> P(K), Q(K), R(L), S(L);
  UnionFind U(N), V(N);
  rep(i, K) {
    cin >> P[i] >> Q[i];
    P[i]--, Q[i]--;
    U.unite(P[i], Q[i]);
  }
  rep(i, L) {
    cin >> R[i] >> S[i];
    R[i]--, S[i]--;
    V.unite(R[i], S[i]);
  }
  map<pair<int, int>, int> G;
  rep(i, N) {
    auto p = make_pair(U.root(i), V.root(i));
    if(G.count(p)) G[p]++;
    else G[p] = 1;
  }
  rep(i, N)
    cout << G[make_pair(U.root(i), V.root(i))] << ' ';
  cout << endl;
  return 0;
}

