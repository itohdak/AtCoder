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
  int N, L;
  cin >> N >> L;
  vector<pair<pair<int, int>, ll>> C(N);
  rep(i, N) {
    cin >> C[i].first.first >> C[i].first.second >> C[i].second;
  }
  sort(all(C));
  vector<ll> dp(L+1, longinf);
  dp[0] = 0;
  rep(i, N) {
    dp[C[i].first.second] = min(dp[C[i].first.first]+C[i].second,
                                dp[C[i].first.second]);
    int j = C[i].first.second-1;
    while(j >= 0 && dp[j] > dp[C[i].first.second]) {
      dp[j] = dp[C[i].first.second];
      j--;
    }
  }
  cout << dp[L] << endl;
  return 0;
}
