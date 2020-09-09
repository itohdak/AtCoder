#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x, y; string w;
  cin >> y >> x >> w;
  x--; y--;
  vector<string> S(9);
  rep(i, 9) cin >> S[i];
  int dx=0, dy=0;
  if(w == "R") dy = 1;
  else if(w == "L") dy = -1;
  else if(w == "U") dx = -1;
  else if(w == "D") dx = 1;
  else if(w == "RU") dx = -1, dy = 1;
  else if(w == "RD") dx = 1, dy = 1;
  else if(w == "LU") dx = -1, dy = -1;
  else dx = 1, dy = -1;
  rep(_, 4) {
    cout << S[x][y];
    x += dx; y += dy;
    if(x > 8) {
      x = 16-x;
      dx *= -1;
    }
    if(x < 0) {
      x = -x;
      dx *= -1;
    }
    if(y > 8) {
      y = 16-y;
      dy *= -1;
    }
    if(y < 0) {
      y = -y;
      dy *= -1;
    }
  }
  cout << endk;
  return 0;
}
