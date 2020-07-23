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
  vector<pair<int, int>> ans(100);
  int sumx = 0;
  int i = 100;
  while(i > 0) {
    int tmpx = sumx + i;
    sumx += 2*i;
    int sumy = 0;
    while(i > 0 && sumy+2*i <= 1500) {
      ans[i-1].first = tmpx;
      ans[i-1].second = sumy+i;
      sumy += 2*i;
      i--;
    }
  }
  rep(i, 100) cout << ans[i].first << ' ' << ans[i].second << "\n";
  return 0;
}
