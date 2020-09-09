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
  int h, w; cin >> h >> w;
  vector<vector<int>> C(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> C[i][j];
  vector<vector<int>> sumB(h+1, vector<int>(w+1)), sumW(h+1, vector<int>(w+1));
  rep(i, h) rep(j, w) sumB[i+1][j+1] = sumB[i+1][j] + ((i+j)%2==0 ? C[i][j] : 0);
  rep(j, w) rep(i, h) sumB[i+1][j+1] += sumB[i][j+1];
  rep(i, h) rep(j, w) sumW[i+1][j+1] = sumW[i+1][j] + ((i+j)%2==1 ? C[i][j] : 0);
  rep(j, w) rep(i, h) sumW[i+1][j+1] += sumW[i][j+1];
  ll ans = 0;
  rep(i, h) rep(j, w) REP(k, i, h) REP(l, j, w) {
    int b = sumB[k+1][l+1]+sumB[i][j]-sumB[i][l+1]-sumB[k+1][j];
    int w = sumW[k+1][l+1]+sumW[i][j]-sumW[i][l+1]-sumW[k+1][j];
    if(b == w) chmax(ans, (k-i+1)*(l-j+1));
  }
  cout << ans << endk;
  return 0;
}
