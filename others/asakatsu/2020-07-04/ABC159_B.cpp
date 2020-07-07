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
  string t = s;
  reverse(all(t));
  int n = s.size();
  string s1 = s.substr(0, (n-1)/2);
  string s2 = s.substr((n-1)/2+1);
  string t1 = s1, t2 = s2;
  reverse(all(t1)), reverse(all(t2));
  cout << (s==t&&s1==t1&&s2==t2 ? "Yes" : "No") << "\n";
  return 0;
}
