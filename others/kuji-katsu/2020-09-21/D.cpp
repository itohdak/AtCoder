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
  int n; cin >> n;
  vector<int> X(n), Y(n);
  vector<ll> H(n);
  rep(i, n) cin >> X[i] >> Y[i] >> H[i];
  for(int i=0; i<=100; i++) {
    for(int j=0; j<=100; j++) {
      ll h = -1;
      bool ok = true;
      rep(k, n) {
        int dx = abs(i-X[k]);
        int dy = abs(j-Y[k]);
        if(H[k] == 0) continue;
        if(h == -1) h = H[k]+dx+dy;
        else if(h != H[k]+dx+dy) {
          ok = false;
          break;
        }
      }
      if(!ok) continue;
      if(h != -1) {
        rep(k, n) {
          int dx = abs(i-X[k]);
          int dy = abs(j-Y[k]);
          if(H[k] != 0) continue;
          if(h > H[k]+dx+dy) {
            ok = false;
            break;
          }
        }
      } else {
        h = longinf;
        rep(k, n) {
          int dx = abs(i-X[k]);
          int dy = abs(j-Y[k]);
          if(H[k] != 0) continue;
          chmin(h, H[k]+dx+dy);
        }
      }
      if(!ok) continue;
      cout << i << ' ' << j << ' ' << h << endk;
      return 0;
    }
  }
  return 0;
}
