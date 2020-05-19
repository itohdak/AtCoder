#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  ll dist;
  ll mx = 0;
  ll mxi;
  rep(i, N) {
    if(i != 0) {
      cout << "? " << 1 << " " << i+1 << endl;
      cin >> dist;
      if(dist > mx) {
        mx = dist;
        mxi = i;
      }
    }
  }
  mx = 0;
  rep(i, N) {
    if(i != mxi) {
      cout << "? " << mxi+1 << " " << i+1 << endl;
      cin >> dist;
      mx = max(dist, mx);
    }
  }
  cout << "! " << mx << endl;
  return 0;
}
