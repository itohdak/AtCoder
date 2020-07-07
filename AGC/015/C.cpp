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
  int n, m, q; cin >> n >> m >> q;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<int>> cntV(n+1, vector<int>(m+1));
  rep(i, n) rep(j, m) cntV[i+1][j+1] = (S[i][j]=='1');
  rep(i, n) rep(j, m) cntV[i+1][j+1] += cntV[i+1][j];
  rep(j, m) rep(i, n) cntV[i+1][j+1] += cntV[i][j+1];
  vector<vector<int>> cntEc(n+1, vector<int>(m+1));
  rep(i, n) rep(j, m) cntEc[i+1][j+1] += (j && S[i][j]-'0' && S[i][j-1]-'0');
  rep(i, n) rep(j, m) cntEc[i+1][j+1] += cntEc[i+1][j];
  rep(j, m) rep(i, n) cntEc[i+1][j+1] += cntEc[i][j+1];
  vector<vector<int>> cntEr(n+1, vector<int>(m+1));
  rep(j, m) rep(i, n) cntEr[i+1][j+1] += (i && S[i][j]-'0' && S[i-1][j]-'0');
  rep(i, n) rep(j, m) cntEr[i+1][j+1] += cntEr[i+1][j];
  rep(j, m) rep(i, n) cntEr[i+1][j+1] += cntEr[i][j+1];
  // cout << cntEc << "\n" << cntEr << "\n";
  while(q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; // x2--; y2--;
    int v = cntV[x2][y2] - cntV[x1][y2] - cntV[x2][y1] + cntV[x1][y1];
    int ec = cntEc[x2][y2] - cntEc[x1][y2] - cntEc[x2][y1+1] + cntEc[x1][y1+1];
    int er = cntEr[x2][y2] - cntEr[x1+1][y2] - cntEr[x2][y1] + cntEr[x1+1][y1];
    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "\n";
    // cout << cntEc[x2][y2] << " - "
    //      << cntEc[x1][y2] << " - "
    //      << cntEc[x2][y1] << " + "
    //      << cntEc[x1][y1] << "\n";
    // cout << ec << ' ' << er << "\n";
    cout << v-(ec+er) << "\n";
  }
  return 0;
}
