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
  vector<ll> X(N), Y(N);
  rep(i, N) cin >> X[i] >> Y[i];
  int cnt = 0;
  rep(i, N) REP(j, i+1, N) REP(k, j+1, N) {
    ll v1x = X[j]-X[i], v1y = Y[j]-Y[i];
    ll v2x = X[k]-X[i], v2y = Y[k]-Y[i];
    ll outer = v1x*v2y-v1y*v2x;
    if(outer!=0 && outer%2==0) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
