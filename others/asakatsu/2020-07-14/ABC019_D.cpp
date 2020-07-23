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
  int n; cin >> n;
  ll mx = 0;
  int mxi = -1;
  rep(i, n) {
    if(i) {
      cout << "? " << 1 << ' ' << i+1 << endl;
      int res; cin >> res;
      if(mx < res) {
        mx = res;
        mxi = i;
      }
    }
  }
  mx = 0;
  rep(i, n) {
    if(i != mxi) {
      cout << "? " << mxi+1 << ' ' << i+1 << endl;
      int res; cin >> res;
      if(mx < res) {
        mx = res;
      }
    }
  }
  cout << "! " << mx << endl;
  return 0;
}
