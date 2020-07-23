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
  int d = log10(n)+1;
  // cout << d << "\n";
  ll ans = 0;
  for(int i=1; i<d; i+=2) {
    ans += 9*pow(10,i-1);
  }
  if(d%2) ans += n-pow(10,d-1)+1;
  cout << ans << "\n";
  return 0;
}
