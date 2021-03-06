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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int l = 0, r = 0;
  ll ans = 1000;
  while(l < n-1) {
    while(r < n-1 && A[r] <= A[r+1]) r++;
    ll cur = ans / A[l];
    ans -= cur * A[l];
    ans += cur * A[r];
    while(r < n-1 && A[r] > A[r+1]) r++;
    l = r;
  }
  cout << ans << "\n";
  return 0;
}
