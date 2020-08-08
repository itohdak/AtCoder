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
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<int> cnt(26, inf);
  rep(i, n) {
    vector<int> cnt2(26);
    for(char c: S[i]) cnt2[c-'a']++;
    rep(j, 26) cnt[j] = min(cnt2[j], cnt[j]);
  }
  rep(i, 26) {
    cout << string(cnt[i], 'a'+i);
  }
  cout << "\n";
  return 0;
}
