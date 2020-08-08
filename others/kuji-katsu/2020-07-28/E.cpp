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
  ll k; cin >> k;
  int n = 50;
  vector<ll> ans(n);
  rep(i, n) ans[i] = i+k/n;
  k %= n;
  rep(i, n) {
    if(i < k) ans[i] += n+1;
    ans[i] -= k;
  }
  cout << n << "\n";
  rep(i, n) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
