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
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  ll S = 0, X = 0;
  S = A[0] + A[1];
  REP(i, 2, N) X ^= A[i];
  if((S-X)&1) {
    cout << -1 << "\n";
    return 0;
  }
  ll D = (S-X)>>1;
  if(D > A[0]) {
    cout << -1 << "\n";
    return 0;
  }
  vector<ll> d(45);
  {
    int i = 0;
    while(X > 0) {
      d[i] = X&1;
      if(d[i] && (D>>i)&1) {
        cout << -1 << "\n";
        return 0;
      }
      X >>= 1;
      i++;
    }
  }
  rrep(i, 45) {
    if((D^(d[i]<<i)) > A[0]) continue;
    D ^= (d[i]<<i);
  }
  cout << (D==0 ? -1 : A[0]-D) << "\n";
  return 0;
}
