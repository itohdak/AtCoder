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
  int n; ll a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  // ai-d <= a(i+1) <= ai-c // m
  // ai+c <= a(i+1) <= ai+d // n-1-m
  bool ok = false;
  for(int m=0; m<=n-1; m++) {
    ll mn = -d*m+c*(n-1-m);
    ll mx = -c*m+d*(n-1-m);
    if(mn <= b-a && b-a <= mx) ok = true;
  }
  cout << (ok ? "YES" : "NO") << "\n";
  return 0;
}
