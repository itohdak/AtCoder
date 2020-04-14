#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  ll T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  if(A1 < B1) {
    swap(A1, B1);
    swap(A2, B2);
  }
  ll d = (A1-B1)*T1 + (A2-B2)*T2;
  if(d == 0) cout << "infinity" << endl;
  else if(d > 0) cout << 0 << endl;
  else {
    ll d1 = (A1-B1)*T1;
    d = abs(d);
    ll cnt = d1/d+1;
    // if(d1%d) cout << cnt*2-1 << endl;
    // else     cout << cnt*2-2 << endl;
    cout << (d1%d ? cnt*2 : cnt*2-1)-1 << endl;
  }
  return 0;
}
