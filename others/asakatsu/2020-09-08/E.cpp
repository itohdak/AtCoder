#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  // n == i * (i+1) / 2
  int m = 0;
  rep(i, n+1) {
    if(i*(i+1)/2 == n) {
      m = i+1;
      break;
    } else if(i*(i+1)/2 > n) {
      cout << "No" << endk;
      return 0;
    }
  }
  cout << "Yes" << endk;
  vector<vector<int>> ans(m, vector<int>(m-1));
  int tmp = 1;
  rep(i, m) REP(j, i, m-1) ans[i][j] = tmp++;
  tmp = 1;
  rep(j, m) REP(i, j+1, m) ans[i][j] = tmp++;
  cout << m << endk;
  rep(i, m) {
    cout << m-1 << ' ';
    rep(j, m-1) cout << ans[i][j] << ' ';
    cout << endk;
  }
  return 0;
}
