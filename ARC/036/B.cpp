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
  int n; cin >> n;
  vector<ll> H(n); rep(i, n) cin >> H[i];
  int l = 0, r = 0;
  int ans = 0;
  while(l < n) {
    while(r < n-1 && H[r] < H[r+1]) r++;
    while(r < n-1 && H[r] > H[r+1]) r++;
    ans = max(r-l+1, ans);
    if(r == n-1) break;
    l = r;
  }
  cout << ans << "\n";
  return 0;
}
