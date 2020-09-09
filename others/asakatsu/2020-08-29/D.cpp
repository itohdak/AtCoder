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
  ll s; cin >> s;
  // (x1, y1), (x2, y2)
  // S = abs(x1 * y2 - x2 * y1)
  // x1 = 1e9, x2 = 1
  // S = abs(1e9 * y2 - y1)
  //   = abs(1e9 * (y2-1) + 1e9-y1))
  ll y2 = min(s/(ll)1e9+1, (ll)1e9);
  ll y1 = (ll)1e9*y2-s;
  cout << 0 << ' ' << 0 << ' '
       << (ll)1e9 << ' ' << y1 << ' '
       << 1 << ' ' << y2 << endk;
  return 0;
}
