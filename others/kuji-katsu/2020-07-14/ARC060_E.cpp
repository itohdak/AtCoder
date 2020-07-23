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

class Doubling {
public:
  int N;
  int logK;
  vector<vector<int>> next;

  Doubling(int N, vector<int>& ini, ll K) {
    logK = log2(K);
    next = vector<vector<int>>(logK+1, vector<int>(N));
    rep(i, N) next[0][i] = ini[i];
    rep(k, logK) {
      rep(i, N) {
        next[k+1][i] = (next[k][i] == -1 ? -1 : next[k][next[k][i]]);
      }
    }
  }

  int query(int p, ll q) {
    for(int k=logK; k>=0; k--) {
      if(p == -1) break;
      if((q>>k)&1) p = next[k][p];
    }
    return p;
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> X(n); rep(i, n) cin >> X[i];
  ll l; cin >> l;
  vector<int> next(n);
  rep(i, n) next[i] = --upper_bound(all(X), X[i]+l) - begin(X);
  vector<int> rnext(n);
  rrep(i, n) rnext[i] = lower_bound(all(X), X[i]-l) - begin(X);
  Doubling dbl(n, next, n);
  Doubling rdbl(n, rnext, n);
  auto bsearch = [&](int s, int t) {
    int ok = n, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      if(s < t) (dbl.query(s, mid)>=t ? ok : ng) = mid;
      else      (rdbl.query(s, mid)<=t ? ok : ng) = mid;
    }
    return ok;
  };
  int q; cin >> q;
  rep(_, q) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << bsearch(a, b) << "\n";
  }
  return 0;
}
