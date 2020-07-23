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
  int n; cin >> n;
  string s; cin >> s;
  map<char, vector<int>> mp;
  rep(i, n) {
    mp[s[i]].push_back(i);
  }
  int ans = 0;
  auto dfs = [&](auto dfs, int pos, int cur) {
    if(cur == 3) {
      ans++;
      return;
    }
    rep(i, 10) {
      char c = '0'+i;
      auto ret = upper_bound(all(mp[c]), pos);
      if(ret == mp[c].end()) continue;
      dfs(dfs, *ret, cur+1);
    }
  };
  dfs(dfs, -1, 0);
  cout << ans << "\n";
  return 0;
}
