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
  vector<ll> H(n); rep(i, n) cin >> H[i];
  bool ok = true;
  ll mn = 0;
  rep(i, n) {
    if(H[i]<mn) ok = false;
    if(H[i]-1>=mn) mn = H[i]-1;
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
