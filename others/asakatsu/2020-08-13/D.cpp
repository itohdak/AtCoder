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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> S(n); rep(i, n) cin >> S[i];
  sort(all(S), greater<ll>());
  while(!S.empty() && S.back() == 0) S.pop_back();
  reverse(all(S));
  auto bsearch =
    [&](ll m) {
      auto test =
        [&](ll k) {
          return end(S)-lower_bound(all(S), k)<=m;
        };
      ll ok = longinf, ng = -1;
      while(ok-ng>1) {
        ll mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };

  int q; cin >> q;
  vector<ll> K(q);
  rep(i, q) {
    cin >> K[i];
    cout << bsearch(K[i]) << endk;
  }
  return 0;
}
