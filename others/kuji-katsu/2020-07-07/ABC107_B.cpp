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
  int h, w; cin >> h >> w;
  vector<string> A(h); rep(i, h) cin >> A[i];
  set<int> remH, remW;
  rep(i, h) {
    bool ok = true;
    rep(j, w) ok &= (A[i][j]=='.');
    if(ok) remH.insert(i);
  }
  rep(j, w) {
    bool ok = true;
    rep(i, h) ok &= (A[i][j]=='.');
    if(ok) remW.insert(j);
  }
  rep(i, h) {
    rep(j, w) if(!remH.count(i) && !remW.count(j)) cout << A[i][j];
    if(!remH.count(i)) cout << "\n";
  }
  return 0;
}
