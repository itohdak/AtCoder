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
ll binary_pow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) {
      ans *= tmp;
      ans %= mod;
    }
    N /= 2;
    tmp *= tmp;
    tmp %= mod;
  }
  return ans;
}
#define MAX_N 200005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r); // n * (n-1) * ... * (n-r+1)
  ans = (ans * finv[r]) % mod; // フェルマーの小定理
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> P(N);
  rep(i, N) {
    cin >> P[i];
    if(P[i] == -1) continue;
    P[i]--;
  }

  UnionFind uf(N);
  ll ans = 0;
  int n = 0;
  rep(i, N) {
    if(P[i] == -1) {
      n++;
      continue;
    }
    if(!uf.same(i, P[i])) {
      (ans += 1) %= mod;
      uf.unite(i, P[i]);
    }
  }
  (ans *= binary_pow(N-1, n)) %= mod;
  cout << ans << endl;

  set<int> root;
  int cnt = 0;
  rep(i, N) {
    if(P[i] == -1) {
      if(uf.nGroup[uf.root(i)]) cnt++;
      continue;
    }
    root.insert(uf.root(i));
  }
  make();
  int m = root.size();
  (ans += n*(N-1)) %= mod;
  cout << ans << endl;
  ll tmp = comb(n+m-2, n-1);
  // (ans += tmp) %= mod;
  ans -= cnt*tmp;
  cout << ans << endl;
  return 0;
}
