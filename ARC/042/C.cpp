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
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N, P;
  cin >> N >> P;
  vector<pair<ll, ll>> item(N);
  rep(i, N) cin >> item[i].first >> item[i].second;
  sort(all(item), greater<pair<ll, ll>>());
  ll ans = 0;
  vector<vector<ll>> dp(N+1, vector<ll>(P+105));
  rep(i, N) {
    rep(j, P+105) {
      // 選ばない
      dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
      // 選ぶ
      if(j+item[i].first < P+item[i].first+1) {
        dp[i+1][j+item[i].first] = max(dp[i][j]+item[i].second,
                                       dp[i+1][j+item[i].first]);
      }
    }
    ans = max(*max_element(all(dp[i+1])), ans);
  }
  cout << ans << endl;
  return 0;
}
