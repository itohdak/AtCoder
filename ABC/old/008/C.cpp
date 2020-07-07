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
  rep(i, n) { // for Ci (i=1..N)
    rep(j, n) { // where Ci is
      int d = ndiv[i];
      for(int k=0; k<=min(d, j); k+=2) { // how many times Ci will be turned over
        // comb(d, k) * comb(n-1-d, j-k) * fact(j) * fact(n-1-j) / fact(n);
        if(d < k || n-1-d < j-k) continue;
        double tmp = 1;
        rep(l, k) tmp *= d-l;
        rep(l, k) tmp /= k-l;
        rep(l, j-k) tmp *= n-1-d-l;
        rep(l, j-k) tmp /= j-k-l;
        rep(l, j) tmp *= j-l;
        rep(l, n-1-j) tmp *= n-1-j-l;
        rep(l, n) tmp /= n-l;
        ans += tmp;
      }
    }
  }
  cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}
