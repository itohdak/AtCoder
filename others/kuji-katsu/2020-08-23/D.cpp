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
  ll N; cin >> N;
  // 4*h*n*w == N*n*w + N*h*w + N*h*n
  // w*(4*h*n-N*h-N*n) == N*h*n
  for(ll h=1; h<=3500; h++) {
    for(ll n=1; n<=3500; n++) {
      ll a = 4*h*n-N*h-N*n;
      ll b = N*h*n;
      if(a == 0) {
        if(b == 0) {
          cout << h << ' ' << n << ' ' << 1 << endk;
          return 0;
        }
      } else {
        if(b % a == 0 && b/a > 0) {
          cout << h << ' ' << n << ' ' << b/a << endk;
          return 0;
        }
      }
    }
  }
  return 0;
}
