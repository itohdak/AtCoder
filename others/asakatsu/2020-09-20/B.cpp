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
  int a[4];
  string s; cin >> s;
  rep(i, 4) a[i] = s[i]-'0';
  rep(i, 1<<3) {
    int tmp = a[0];
    rep(j, 3) {
      if((i>>j)&1) tmp += a[j+1];
      else tmp -= a[j+1];
    }
    if(tmp == 7) {
      cout << a[0];
      rep(j, 3) {
        if((i>>j)&1) cout << '+';
        else cout << '-';
        cout << a[j+1];
      }
      cout << "=7" << endk;
      break;
    }
  }
  return 0;
}
