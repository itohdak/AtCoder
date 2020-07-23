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
  string s;
  getline(cin, s);
  int n; cin >> n;
  vector<string> T(n);
  rep(i, n) cin >> T[i];
  vector<string> word;
  {
    int l = 0, r = 0;
    int n = s.size();
    while(l < n) {
      while(r < n && s[r] != ' ') r++;
      word.push_back(s.substr(l, r-l));
      r++;
      l = r;
    }
  }
  for(string w: word) {
    bool done= false;
    rep(i, n) {
      if(w.size() != T[i].size()) continue;
      bool ok = true;
      rep(j, w.size()) {
        if(T[i][j] != '*' && w[j] != T[i][j]) ok = false;
      }
      if(ok) {
        cout << string(w.size(), '*') << ' ';
        done = true;
        break;
      }
    }
    if(!done) cout << w << ' ';
  }
  cout << "\n";
  return 0;
}
