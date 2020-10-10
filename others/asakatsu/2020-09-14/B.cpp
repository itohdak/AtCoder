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
  int a, b; cin >> a >> b;
  vector<int> A(a), B(b);
  vector<char> res(10, 'x');
  rep(i, a) {
    cin >> A[i];
    res[(A[i]+9)%10] = '.';
  }
  rep(i, b) {
    cin >> B[i];
    res[(B[i]+9)%10] = 'o';
  }
  cout << res[6] << ' ' << res[7] << ' ' << res[8] << ' ' << res[9] << endk;
  cout << ' ' << res[3] << ' ' << res[4] << ' ' << res[5] << endk;
  cout << "  " << res[1] << ' ' << res[2] << endk;
  cout << "   " << res[0] << endk;
  return 0;
}
