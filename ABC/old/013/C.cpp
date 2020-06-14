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
  ll N, H, A, B, C, D, E;
  cin >> N >> H >> A >> B >> C >> D >> E;
  if(E*N <= H) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = longinf;
  rep(i, N+1) {
    // B * i + D * (n-i) >= diff
    // (B-D) * i + D * n >= diff
    // (B-D) * i >= diff - D * n
    // i >= (diff-D*n) / (B-D)
    // i <= n
    ll diff = E*i-H+1;
    int n = N-i;
    ll j = (diff-D*n+B-D-1) / (B-D);
    if(j > n) continue;
    // cout << (diff-D*n+B-D-1) << '/' << (B-D) << ' ' << j << endl;
    // cout << i << ' ' << j << ' ' << (A-C)*max(j, 0LL) + C*n << endl;
    ans = min((A-C)*max(j, 0LL) + C*n, ans);
  }
  cout << ans << endl;
  return 0;
}
