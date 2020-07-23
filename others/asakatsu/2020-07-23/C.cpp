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
  int n, k; cin >> n >> k;
  double ans = 0;
  for(int i=1; i<=n; i++) {
    int cnt = 0;
    int n = i;
    while(n < k) {
      cnt++;
      n *= 2;
    }
    ans += pow((double)1/2, cnt);
  }
  cout << fixed << setprecision(10) << ans/n << "\n";
  return 0;
}
