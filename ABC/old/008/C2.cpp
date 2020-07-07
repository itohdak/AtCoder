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
  vector<ll> C(n); rep(i, n) cin >> C[i];
  double ans = 0;
  vector<int> ndiv(n);
  rep(i, n) rep(j, n) if(i != j && C[i]%C[j]==0) ndiv[i]++;
  rep(i, n) {
    int d = ndiv[i];
    ans += (d%2 ? (double)1/2 : (double)(d+2)/(2*d+2));
  }
  cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}
