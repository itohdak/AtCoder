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
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  vector<vector<pair<ll, ll>>> cnt(3);
  rep(i, N) {
    cin >> A[i] >> B[i];
    if(A[i] < B[i]) cnt[0].push_back({A[i], B[i]});
    else if(A[i] == B[i]) cnt[1].push_back({A[i], B[i]});
    else cnt[2].push_back({A[i], B[i]});
  }
  ll ans = 0;
  if(cnt[0].size() == 0) { // all equal
    ans = 0;
  } else {
    for(auto ele: cnt[0]) ans += ele.first;
    for(auto ele: cnt[1]) ans += ele.first;
    sort(all(cnt[2]), [&](pair<ll, ll>& p1, pair<ll, ll>& p2) {
        return p1.second < p2.second;
      });
    rep(i, cnt[2].size()) {
      if(i) ans += cnt[2][i].first;
      else  ans += cnt[2][i].first - cnt[2][i].second;
    }
  }
  cout << ans << "\n";
  return 0;
}
