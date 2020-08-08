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
  int t1, t2; cin >> t1 >> t2;
  ll a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
  ll d1 = a1-b1, d2 = a2-b2;
  if(d1<0) {
    swap(a1, b1);
    swap(a2, b2);
    d1 *= -1;
    d2 *= -1;
  }
  if(d1*t1+d2*t2==0) cout << "infinity" << endk;
  else if(d1*t1+d2*t2>0) cout << 0 << endk;
  else {
    ll dd = abs(d1*t1+d2*t2);
    ll n = ((d1*t1)+dd-1)/dd;
    ll cnt = n*2-1;
    if(dd*n==d1*t1) cnt++;
    cout << cnt << endk;
  }
  return 0;
}
