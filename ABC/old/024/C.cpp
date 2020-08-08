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
  ll n; int d, k; cin >> n >> d >> k;
  vector<ll> L(d), R(d), S(k), T(k);
  rep(i, d) {
    cin >> L[i] >> R[i];
    L[i]--; R[i]--;
  }
  rep(i, k) {
    cin >> S[i] >> T[i];
    S[i]--; T[i]--;
  }
  vector<int> ans(k);
  rep(i, k) {
    ll l = S[i], r = S[i];
    rep(j, d) {
      if(L[j] <= r && R[j] >= l) {
        l = min(l, L[j]);
        r = max(r, R[j]);
      }
      if(l <= T[i] && T[i] <= r) {
        ans[i] = j+1;
        break;
      }
    }
  }
  rep(i, k) cout << ans[i] << endk;
  return 0;
}
