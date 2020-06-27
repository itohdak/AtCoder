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
  vector<ll> A(7);
  rep(i, 7) cin >> A[i];
  ll ans = 0;
  ans += A[0]/2 * 2;
  ans += A[1]   * 1;
  ans += A[3]/2 * 2;
  ans += A[4]/2 * 2;
  int id[] = {0, 3, 4};
  switch(A[0]%2+A[3]%2+A[4]%2) {
  case 3:
    ans += 3;
    break;
  case 2:
    rep(i, 3) {
      if(A[id[i]]%2==0) {
        if(A[id[i]] > 0) ans += 1;
        break;
      }
    }
    break;
  case 1:
    break;
  default: // 0
    break;
  }
  cout << ans << endl;
  return 0;
}
