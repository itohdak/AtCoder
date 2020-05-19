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
  vector<ll> C(N);
  ll minAll=longinf, minOdd=longinf;
  rep(i, N) {
    cin >> C[i];
    if(1-i%2) minOdd = min(C[i], minOdd);
    minAll = min(C[i], minAll);
  }
  minAll = min(minOdd, minAll);
  int Q;
  cin >> Q;
  ll buyAll=0, buyOdd=0;
  vector<ll> buy(N);
  ll ans = 0;
  rep(q, Q) {
    int t;
    cin >> t;
    int x;
    ll a, rem;
    switch(t) {
      case 1:
        cin >> x >> a;
        --x;
        rem = C[x]-buy[x]-buyAll-(1-x%2 ? buyOdd : 0);
        if(rem >= a) {
          buy[x] += a;
          minAll = min(rem-a, minAll);
          if(1-x%2) minOdd = min(rem-a, minOdd);
          ans += a;
        }
        break;
      case 2:
        cin >> a;
        if(minOdd >= a) {
          buyOdd += a;
          minOdd -= a;
          minAll = min(minAll, minOdd);
          ans += a * ((N+1)/2);
        }
        break;
      case 3:
        cin >> a;
        if(minAll >= a) {
          buyAll += a;
          minAll -= a;
          minOdd -= a;
          ans += a * N;
        }
        break;
    }
    // cout << ans << ' ' << minOdd << ' ' << minAll << endl;
  }
  cout << ans << endl;
  return 0;
}
