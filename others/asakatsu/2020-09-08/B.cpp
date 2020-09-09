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
  vector<vector<int>> C(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> C[i][j];
  bool ok = true;
  rep(i, 2) rep(j, 2) {
    ok &= (C[i+1][j+1]-C[i][j+1] == C[i+1][0]-C[i][0]);
  }
  rep(j, 2) rep(i, 2) {
    ok &= (C[i+1][j+1]-C[i+1][j] == C[0][j+1]-C[0][j]);
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
