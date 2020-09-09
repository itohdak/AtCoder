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
  int n; cin >> n;
  vector<int> P(n), Q(n);
  string ps, qs;
  rep(i, n) {
    cin >> P[i];
    ps += char('0'+P[i]);
  }
  rep(i, n) {
    cin >> Q[i];
    qs += char('0'+Q[i]);
  }
  vector<string> v;
  vector<bool> used(n);
  auto dfs = [&](auto dfs, int cur, string tmp) -> void {
    if(cur == n) {
      v.push_back(tmp);
      return;
    }
    rep(i, n) {
      if(used[i]) continue;
      used[i] = true;
      dfs(dfs, cur+1, tmp+(char)('1'+i));
      used[i] = false;
    }
  };
  dfs(dfs, 0, "");
  cout << abs(find(all(v), qs) - find(all(v), ps)) << endk;
  return 0;
}
