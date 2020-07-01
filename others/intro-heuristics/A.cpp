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
  int D;
  cin >> D;
  vector<ll> C(26);
  rep(i, 26) cin >> C[i];
  vector<vector<ll>> S(D, vector<ll>(26));
  rep(i, D) rep(j, 26) {
    cin >> S[i][j];
  }
  vector<vector<int>> Last(26);
  rep(i, 26) Last[i].push_back(0);
  vector<int> T(D);
  ll sum = 0;
  rep(i, D) {
    cin >> T[i]; T[i]--;
    sum += S[i][T[i]];
    Last[T[i]].push_back(i+1);
    rep(j, 26) {
      sum -= C[j] * (i+1 - Last[j].back());
    }
    // cout << sum << "\n";
  }
  rep(i, 26) Last[i].push_back(D+1);
  cout << Last << "\n";
  cout << sum << "\n";

  int M;
  cin >> M;
  vector<int> d(M), q(M);
  rep(i, M) {
    cin >> d[i] >> q[i];
    d[i]--; q[i]--;
    int from = T[d[i]];
    int to = q[i];
    ll curSum = sum;
    curSum -= S[d[i]][from];
    curSum += S[d[i]][to];
    auto itr1 = lower_bound(all(Last[from]), d[i]+1);
    auto itr2 = lower_bound(all(Last[to]), d[i]+1);
    cout << d[i]+1 << "\n";

    cout << *(--itr1) << ' ' << *(++(++itr1)) << "\n";
    curSum -= C[from] * (d[i]-*(--itr1)) * (d[i]-*(--itr1)+1) / 2;
    curSum -= C[from] * (*(++(++itr1))-d[i]) * (*(++(++itr1))-d[i]+1) / 2;
    curSum += C[from] * (*(++(++itr1))-*(--itr1)-1) * (*(++(++itr1))-*(--itr1)) / 2;

    cout << *(--itr2) << ' ' << *(++itr2) << "\n";
    curSum += C[to] * (d[i]-*(--itr2)) * (d[i]-*(--itr2)+1) / 2;
    curSum += C[to] * (*(++itr2)-d[i]) * (*(++itr2)-d[i]+1) / 2;
    curSum -= C[to] * (*(++itr2)-*(--itr2)-1) * (*(++itr2)-*(--itr2)) / 2;

    cout << curSum << "\n";
  }
  return 0;
}
