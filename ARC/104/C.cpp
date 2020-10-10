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
  bool ok = true;
  vector<pair<int, int>> A(2*n, {-1, 0});
  map<int, int> mp;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if(a != -1) {
      a--;
      if(A[a].first != -1) ok = false;
      A[a] = {i, 1};
      mp[i]++;
    }
    if(b != -1) {
      b--;
      if(A[b].first != -1) ok = false;
      A[b] = {i, -1};
      mp[i]++;
    }
    if(a != -1 && b != -1 && a > b) ok = false;
  }
  if(!ok) {
    cout << "No" << endk;
    return 0;
  }
  map<int, int> cnt;
  auto check = [&](int l, int r) {
    // cout << l << ' ' << r << endk;
    // cout << mp << endk;
    // cout << cnt << endk;
    assert((r-l)%2==0);
    bool ok = true;
    for(auto ele: cnt) {
      if(mp[ele.first] != ele.second) ok = false;
    }
    rep(i, (r-l)/2) {
      if(A[l+i].second == -1) ok = false;
    }
    rep(i, (r-l)/2) {
      if(A[l+(r-l)/2+i].second == 1) ok = false;
    }
    rep(i, (r-l)/2) {
      if(A[l+i].first == -1 || A[l+(r-l)/2+i].first == -1) continue;
      if(A[l+i].first != A[l+(r-l)/2+i].first) ok = false;
    }
    return ok;
  };
  vector<vector<bool>> ok2(n+1, vector<bool>(n+1));
  // cout << A << endk;
  rep(i, n) {
    cnt.clear();
    ok2[i][i] = true;
    REP(j, i, n) {
      rep(k, 2) if(A[2*j+k].first != -1) cnt[A[2*j+k].first]++;
      ok2[i][j+1] = check(2*i, 2*(j+1));
    }
  }
  // cout << ok2 << endk;
  vector<bool> dp(n+1);
  dp[0] = true;
  rep(i, n) {
    if(!dp[i]) continue;
    REP(j, i, n+1) {
      if(ok2[i][j]) dp[j] = true;
    }
  }
  cout << (dp[n] ? "Yes" : "No") << endk;
  return 0;
}
