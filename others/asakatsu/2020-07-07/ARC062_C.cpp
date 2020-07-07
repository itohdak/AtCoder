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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> T(n), A(n);
  rep(i, n) cin >> T[i] >> A[i];
  ll prevT = T[0], prevA = A[0];
  rep(i, n) {
    ll mx = max({(prevT+T[i]-1)/T[i], (prevA+A[i]-1)/A[i]});
    prevT = mx * T[i];
    prevA = mx * A[i];
  }
  cout << prevT+prevA << "\n";
  return 0;
}
