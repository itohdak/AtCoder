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
  int N; cin >> N;
  // 4*h*n*w = N * (n*w + h*w + h*n)
  // (4*h*n-N*(n+h)) * w = N*h*n
  rep(h, 3501) rep(n, 3501) {
    ll a = 1LL*4*h*n - 1LL*N*(n+h);
    ll b = 1LL*N*h*n;
    if(a <= 0) continue;
    if(b % a == 0) {
      ll w = b/a;
      cout << h << ' ' << n << ' ' << w << endk;
      return 0;
    }
  }
  return 0;
}
