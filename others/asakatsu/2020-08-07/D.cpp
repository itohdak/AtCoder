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
  int h, w, n; cin >> h >> w >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  int tmp = 0;
  int col = 1;
  vector<vector<int>> ans(h, vector<int>(w));
  while(tmp < h*w) {
    rep(i, A[col-1]) {
      int x = tmp/w;
      int y = (x%2 ? w-tmp%w-1 : tmp%w);
      ans[x][y] = col;
      tmp++;
    }
    col++;
  }
  rep(i, h) {
    rep(j, w) {
      if(j) cout << ' ';
      cout << ans[i][j];
    }
    cout << endk;
  }
  return 0;
}
