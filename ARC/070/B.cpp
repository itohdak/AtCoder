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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<bool>> dpl(n+1, vector<bool>(k+1)), dpr(n+1, vector<bool>(k+1));
  dpl[0][0] = true;
  dpr[n][0] = true;
  rep(i, n) {
    rep(j, k+1) {
      dpl[i+1][j] = dpl[i][j] || dpl[i+1][j];
      dpl[i+1][min(j+A[i], (ll)k)] = dpl[i][j] || dpl[i+1][min(j+A[i], (ll)k)];
    }
  }
  rrep(i, n) {
    rep(j, k+1) {
      dpr[i][j] = dpr[i+1][j] || dpr[i][j];
      dpr[i][min(j+A[i], (ll)k)] = dpr[i+1][j] || dpr[i][min(j+A[i], (ll)k)];
    }
  }
  // cout << dpl << endk;
  // cout << dpr << endk;
  int ans = n;
  rep(i, n) {
    bool ok = false;
    if(A[i] >= k) {
      ans--;
      continue;
    }
    vector<int> sum(k+2);
    rep(j, k+1) sum[j+1] = sum[j] + dpr[i+1][j];
    rep(j, k) {
      // k-A[i] <= j + S < k
      if(dpl[i][j] && sum[k-j]-sum[max(k-A[i]-j, 0LL)]) ok = true;
    }
    if(ok) ans--;
  }
  cout << ans << endk;
  return 0;
}
