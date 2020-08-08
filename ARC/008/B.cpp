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
  int n, m; cin >> n >> m;
  string name, kit;
  cin >> name >> kit;
  vector<int> cnt(26);
  for(char c: kit) cnt[c-'A']++;
  vector<int> cnt2(26);
  for(char c: name) cnt2[c-'A']++;
  int mx = 0;
  rep(i, 26) {
    if(cnt[i] == 0) {
      if(cnt2[i]) {
        cout << -1 << endk;
        return 0;
      } else {
        continue;
      }
    }
    mx = max((cnt2[i]+cnt[i]-1)/cnt[i], mx);
  }
  cout << mx << endk;
  return 0;
}
