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
    C[i][1] = i/pow((ld)4,1);
    C[i][i] = 1/pow((ld)4,i);
    C[0][i] = 1/pow((ld)4,i);
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1]*pow((ld)4,j-1)/pow((ld)4,j);
  }
}
ld comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll d; cin >> n >> d;
  ll x, y; cin >> x >> y;
  if(abs(x)%d || abs(y)%d) {
    cout << 0 << endk;
  } else if(abs(x)/d+abs(y)/d > n) {
    cout << 0 << endk;
  } else if((n-abs(x)/d-abs(y)/d)%2) {
    cout << 0 << endk;
  } else {
    make();
    int cntX = abs(x)/d;
    int cntY = abs(y)/d;
    int rem = n-cntX-cntY;
    ld ans = 0;
    for(int i=0; i<=rem; i+=2) {
      int x1 = cntX+i/2;
      int x2 = i/2;
      int y1 = cntY+(rem-i)/2;
      int y2 = (rem-i)/2;
      ans += comb(n,x1)*comb(n-x1,x2)*comb(n-x1-x2,y1)*comb(n-x1-x2-y1,y2);
    }
    cout << fixed << setprecision(20) << ans << endk;
  }
  return 0;
}
