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
  int N;
  ll L;
  cin >> N >> L;
  vector<ll> A(N), sum(N+1);
  int last = -1;
  rep(i, N) {
    cin >> A[i];
    if(i>0 && A[i]+A[i-1]>=L) {
      last = i;
    }
  }
  if(last == -1) {
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
    REP(i, 1, last) cout << i << endl;
    RREP(i, N-1, last+1) cout << i << endl;
    cout << last << endl;
  }
  return 0;
}
