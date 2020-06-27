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
  vector<int> v;
  vector<string> ans;
  function<void(int, int)> dfs = [&](int cur, int mx) {
    if(cur == N) {
      // cout << v << endl;
      string tmp(N, ' ');
      rep(i, N) tmp[i] = 'a'+v[i];
      ans.push_back(tmp);
      return;
    }
    for(int i=0; i<=mx+1; i++) {
      v.push_back(i);
      dfs(cur+1, max(mx, i));
      v.pop_back();
    }
  };
  dfs(0, -1);
  for(string s: ans) cout << s << "\n";
  return 0;
}
