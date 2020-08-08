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

#define MAX_N 1005
ld C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i/4;
    C[i][i] = 1/pow(4,i);
    C[0][i] = 1/pow(4,i);
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1]/4;
  }
}
ld comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}
void ng() {
  cout << fixed << setprecision(15) << (ld)0 << endk;
  exit(0);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  ll n, d; cin >> n >> d;
  ll x, y; cin >> x >> y;
  if(abs(x)%d!=0 || abs(y)%d!=0) ng();
  ll nx = abs(x)/d, ny = abs(y)/d;
  ll need = nx+ny;
  if(need > n) ng();
  ll rem = n-need;
  if(rem%2) ng();
  ld ans = 0;
  for(int i=0; i<=rem; i+=2) {
    ll nx1 = nx+i/2, nx2 = i/2, ny1 = ny+(rem-i)/2, ny2 = (rem-i)/2;
    assert(nx1+nx2+ny1+ny2 == n);
    ans += comb(n, nx1) * comb(n-nx1, nx2) * comb(ny1+ny2, ny1) * comb(ny2, ny2);
  }
  cout << fixed << setprecision(15) << ans << endk;
  return 0;
}
