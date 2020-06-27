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
  int N;
  cin >> N;
  vector<double> Ax(N), Ay(N);
  double cx=0, cy=0;
  rep(i, N) {
    cin >> Ax[i] >> Ay[i];
    cx += Ax[i];
    cy += Ay[i];
  }
  double d1 = 0;
  rep(i, N) {
    double dx = Ax[i]*N - cx;
    double dy = Ay[i]*N - cy;
    d1 += dx*dx + dy*dy;
  }
  vector<double> Bx(N), By(N);
  cx = cy = 0;
  rep(i, N) {
    cin >> Bx[i] >> By[i];
    cx += Bx[i];
    cy += By[i];
  }
  double d2 = 0;
  rep(i, N) {
    double dx = Bx[i]*N - cx;
    double dy = By[i]*N - cy;
    d2 += dx*dx + dy*dy;
  }
  cout << setprecision(15) << sqrt((double)d2 / d1) << endl;
  return 0;
}
