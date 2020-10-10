#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

string format(char cmd, int i, int j, int k) {
  string ret;
  ret += cmd;
  ret += ' ';
  ret += to_string(i);
  ret += ' ';
  ret += to_string(j);
  ret += ' ';
  ret += to_string(k);
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<string> ans;
  ans.push_back(format('<', 10, 0, 10)); // 1 or 0
  rep(i, 100) {
    ans.push_back(format('+', 10, 100, 100)); // +1
    ans.push_back(format('+', 0, 2, 2)); // +A
    ans.push_back(format('<', 100, 1, 10));
    // ans.push_back(format('<', 100, 1, 0));
  }
  cout << ans.size() << endk;
  for(auto s: ans) cout << s << endk;
  return 0;
}
