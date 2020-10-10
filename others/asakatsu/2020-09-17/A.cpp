#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int y, m, d;
  scanf("%d/%d/%d", &y, &m, &d);
  int days[] = {31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31};
  auto uruu = [&](int y) {
    return (y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0));
  };
  while(true) {
    if(y % (m * d) == 0) {
      cout << y << '/'
           << setfill('0') << right << setw(2) << m << '/'
           << setfill('0') << right << setw(2) << d << endk;
      break;
    }
    d++;
    if((m == 2 && (d > (uruu(y) ? 29 : 28))) ||
       (m != 2 && (d > days[m-1]))) {
      d = 1;
      m++;
    }
    if(m > 12) {
      m = 1;
      y++;
    }
  }
  return 0;
}
