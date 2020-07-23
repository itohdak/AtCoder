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
  int n, m; cin >> n >> m;
  vector<ll> P(m), Y(m);
  vector<set<pair<ll, int>>> C(n);
  rep(i, m) {
    cin >> P[i] >> Y[i];
    P[i]--;
    C[P[i]].emplace(Y[i], i);
  }
  vector<int> ans(m);
  rep(i, n) {
    int j = 1;
    for(auto ele: C[i]) ans[ele.second] = j++;
  }
  rep(i, m) {
    cout << setfill('0') << right << setw(6) << P[i]+1;
    cout << setfill('0') << right << setw(6) << ans[i];
    cout << "\n";
  }
  return 0;
}
