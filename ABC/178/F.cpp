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
  vector<ll> A(n), B(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  rep(i, n) {
    cin >> B[i];
    B[i]--;
  }
  vector<int> posA(n, -1), posB(n, -1);
  rep(i, n) {
    if(i == n-1 || i == 0 || A[i] != A[i+1]) {
      posA[A[i]] = i+1;
    }
  }
  rep(i, n) {
    if(i == 0 || B[i-1] != B[i]) {
      posB[B[i]] = i;
    }
  }
  int mx = 0;
  rep(i, n) {
    if(posA[i] != -1 && posB[i] != -1) {
      chmax(mx, posA[i]-posB[i]);
    }
  }
  // cout << mx << endk;
  vector<int> C(n);
  // cout << B << endk;
  rep(i, n) C[(i+mx)%n] = B[i];
  // cout << C << endk;
  bool ok = true;
  rep(i, n) if(A[i] == C[i]) ok = false;
  if(ok) {
    cout << "Yes" << endk;
    rep(i, n) cout << C[i]+1 << ' ';
    cout << endk;
  } else {
    cout << "No" << endk;
  }
  return 0;
}
