#include <bits/stdc++.h>
// #include <atcoder/all>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
// using namespace atcoder;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n), B(n), C(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n) cin >> C[i];
  sort(all(A));
  sort(all(B));
  sort(all(C));
  vector<ll> cnt(n);
  rep(i, n) cnt[i] = end(C) - lower_bound(all(C), B[i]+1);
  rrep(i, n) if(i) cnt[i-1] += cnt[i];
  ll ans = 0;
  rep(i, n) ans += cnt[lower_bound(all(B), A[i]+1) - begin(B)];
  cout << ans << endk;
  return 0;
}
