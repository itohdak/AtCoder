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
  string s; cin >> s;
  deque<char> q;
  int n = s.size();
  int ans = 0;
  rep(i, n) q.push_back(s[i]);
  while(!q.empty()) {
    if(q.size() == 1) q.pop_front();
    else if(q.front() == q.back()) {
      q.pop_front(); q.pop_back();
    } else if(q.front() == 'x') {
      ans++; q.pop_front();
    } else if(q.back() == 'x') {
      ans++; q.pop_back();
    } else {
      cout << -1 << "\n";
      return 0;
    }
  }
  cout << ans << "\n";
  return 0;
}
