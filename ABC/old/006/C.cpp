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
  int n, m; cin >> n >> m;
  // 2x + 3y + 4z = m
  //  x +  y +  z = n
  //       y + 2z = m-2n
  //-2x -  y      = m-4n
  // z =  (m-2n-y)/2
  // x = (-m+4n-y)/2
  for(int y=0; y<=n; y++) {
    int z2 =  m-2*n-y;
    int x2 = -m+4*n-y;
    if(z2%2==0 && x2%2==0 && z2>=0 && x2>=0) {
      cout << x2/2 << ' ' << y << ' ' << z2/2 << "\n";
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << "\n";
  return 0;
}
