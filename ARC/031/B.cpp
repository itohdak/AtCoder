#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

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
  vector<string> S(10), Sorig(10);
  rep(i, 10) {
    cin >> S[i];
    Sorig[i] = S[i];
  }
  bool ok = false;
  rep(i_, 10) rep(j_, 10) {
    S[i_][j_] = 'o';
    UnionFind uf(100);
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    rep(i, 10) rep(j, 10) {
      if(S[i][j] == 'o') {
        rep(k, 4) {
          int nx = i+dx[k];
          int ny = j+dy[k];
          if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
          if(S[nx][ny] == 'o') uf.unite(i*10+j, nx*10+ny);
        }
      }
    }
    set<int> st;
    rep(k, 100) if(S[k/10][k%10] == 'o') st.insert(uf.root(k));
    if(st.size() == 1) ok = true;
    S[i_][j_] = Sorig[i_][j_];
  }
  cout << (ok ? "YES" : "NO") << endk;
  return 0;
}
