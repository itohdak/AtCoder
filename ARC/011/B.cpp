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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<string> S(n);
  int to[] = {-1, 1, 1, 2, -1,
              4, 9, 8, -1, 3,
              8, 5, 7, 9, -1,
              7, 4, 0, 6, 3,
              -1, 5, 2, 6, -1, 0};
  vector<string> ans;
  rep(i, n) {
    cin >> S[i];
    string tmp;
    for(char c: S[i]) {
      if(c == '.' || c == ',') continue;
      if(c < 'a') {
        if(to[c-'A'] != -1) tmp += to[c-'A']+'0';
      } else {
        if(to[c-'a'] != -1) tmp += to[c-'a']+'0';
      }
    }
    if(tmp != "") ans.push_back(tmp);
  }
  rep(i, ans.size()) {
    if(i) cout << ' ';
    cout << ans[i];
  }
  cout << endk;
  return 0;
}
