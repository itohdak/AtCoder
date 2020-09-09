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
  int n, p; cin >> n >> p;
  vector<int> A(n), B(n), id(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
                  return A[i] > A[j];
                });
  vector<vector<ll>> dp(n+1, vector<ll>(p+500));
  rep(k, n) {
    int i = id[k];
    rep(j, p+500) {
      chmax(dp[k+1][j], dp[k][j]);
      if(j+A[i] < p+500 && j <= p) chmax(dp[k+1][j+A[i]], dp[k][j]+B[i]);
    }
  }
  cout << *max_element(all(dp[n])) << endk;
  return 0;
}
