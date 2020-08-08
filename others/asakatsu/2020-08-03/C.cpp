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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll ave = accumulate(all(A), 0LL)/n;
  if(ave*n != accumulate(all(A), 0LL)) {
    cout << -1 << "\n";
    return 0;
  }
  ll ans = 0;
  int l = 0, r = 0;
  while(l < n) {
    r++;
    ll sum = A[l];
    while(r < n && sum != ave*(r-l)) {
      ans++;
      sum += A[r];
      r++;
    }
    l = r;
  }
  cout << ans << "\n";
  return 0;
}
