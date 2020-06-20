#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  ll K;
  cin >> S >> K;
  int N = S.size();
  int cnt = 0;
  vector<int> C;
  rep(i, N) {
    if(S[i] == '1') cnt++;
    else {
      C.push_back(cnt);
      cnt = 0;
    }
  }
  C.push_back(cnt);
  reverse(all(C));
  // cout << C << endl;
  int n = C.size();
  int m = accumulate(all(C), 0);
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(m+1, vector<ll>(m+1)));
  dp[0][0][0] = 1;
  rep(i, n) { // i番目の区間
    rep(j, m+1) { // 取り出した回数
      if(j > K) continue;
      rep(k, m+1) { // 挿入した回数
        int rem = j-k;
        if(rem < 0) continue;
        rep(l, rem+1) { // ここで挿入する回数
          (dp[i+1][j][k+l] += dp[i][j][k]) %= mod;
        }
        rep(l, C[i]+1) { // ここで取り出す回数
          if(j+l > m) continue;
          if(l == 0) continue;
          (dp[i+1][j+l][k] += dp[i][j][k]) %= mod;
        }
      }
    }
  }
  // rep(i, n+1) {
  //   rep(j, m+1) {
  //     cout << '{';
  //     rep(k, m+1) {
  //       if(k) cout << ' ';
  //       cout << dp[i][j][k];
  //     }
  //     cout << "} ";
  //   }
  //   cout << endl;
  // }
  ll ans = 0;
  rep(i, min(K+1, (ll)m+1)) (ans += dp[n][i][i]) %= mod;
  cout << ans << endl;
  return 0;
}
