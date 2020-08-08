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
  int n; cin >> n;
  vector<set<int>> vst(26);
  string s; cin >> s;
  rep(i, n) vst[s[i]-'a'].insert(i);
  rep(i, 26) vst[i].insert(-1), vst[i].insert(n);
  int q; cin >> q;
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int i; char c;
      cin >> i >> c;
      i--;
      vst[s[i]-'a'].erase(i);
      s[i] = c;
      vst[s[i]-'a'].insert(i);
    } else {
      int l, r;
      cin >> l >> r;
      l--; r--;
      int cnt = 0;
      rep(i, 26) {
        if(*(--vst[i].upper_bound(r)) >= *vst[i].lower_bound(l)) cnt++;
      }
      cout << cnt << "\n";
    }
  }
  return 0;
}
