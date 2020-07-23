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

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll g = A[0];
  rep(i, n) g = gcd(g, A[i]);
  if(k <= *max_element(all(A)) && k % g == 0) cout << "POSSIBLE" << "\n";
  else cout << "IMPOSSIBLE" << "\n";
  return 0;
}
