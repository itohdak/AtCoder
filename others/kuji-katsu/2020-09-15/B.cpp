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
  vector<vector<int>> A(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  int n; cin >> n;
  rep(i, n) {
    int b; cin >> b;
    rep(j, 3) rep(k, 3) if(A[j][k] == b) A[j][k] = 0;
  }
  rep(i, 3) {
    bool ok = true;
    rep(j, 3) if(A[i][j] != 0) ok = false;
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  rep(j, 3) {
    bool ok = true;
    rep(i, 3) if(A[i][j] != 0) ok = false;
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  {
    ll sum = A[0][0] + A[1][1] + A[2][2];
    if(sum == 0) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  {
    ll sum = A[0][2] + A[1][1] + A[2][0];
    if(sum == 0) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
