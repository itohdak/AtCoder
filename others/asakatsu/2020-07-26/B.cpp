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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  s = s.substr(0, s.size()-2);
  while(1) {
    string s1 = s.substr(0, s.size()/2);
    string s2 = s.substr(s.size()/2);
    if(s1 == s2) {
      cout << s.size() << "\n";
      break;
    }
    s = s.substr(0, s.size()-2);
  }
  return 0;
}
