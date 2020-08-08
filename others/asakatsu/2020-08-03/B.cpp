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
  string x; cin >> x;
  int n = x.size();
  bool ok = true;
  int i = 0;
  set<char> st = {'o', 'k', 'u'};
  while(i < n) {
    if(st.count(x[i])) i++;
    else if(i+1 < n && x.substr(i, 2) == "ch") i += 2;
    else {
      ok = false;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << "\n";
  return 0;
}
