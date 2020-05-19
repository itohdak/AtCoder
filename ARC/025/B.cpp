#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> C(H, vector<int>(W));
  vector<vector<int>>
    bl(H+1, vector<int>(W+1)),
    wh(H+1, vector<int>(W+1)),
    sub(H+1, vector<int>(W+1));
  rep(i, H) rep(j, W) {
    cin >> C[i][j];
    if((i+j)%2) wh[i+1][j+1] = C[i][j];
    else        bl[i+1][j+1] = C[i][j];
  }
  rep(i, H) rep(j, W+1) {
    wh[i+1][j] += wh[i][j];
    bl[i+1][j] += bl[i][j];
  }
  rep(j, W) rep(i, H+1) {
    wh[i][j+1] += wh[i][j];
    bl[i][j+1] += bl[i][j];
  }
  rep(i, H+1) rep(j, W+1) sub[i][j] = wh[i][j] - bl[i][j];
  int ans = 0;
  rep(i, H+1) rep(j, W+1) REP(k, i, H+1) REP(l, j, W+1) {
    if(sub[k][l]-sub[i][l]-sub[k][j]+sub[i][j] == 0) ans = max((k-i)*(l-j), ans);
  }
  cout << ans << endl;
  return 0;
}
