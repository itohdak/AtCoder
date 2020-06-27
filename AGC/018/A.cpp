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

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  ll GCD = A[0];
  rep(i, N) GCD = gcd(A[i], GCD);
  if(K > *A.rbegin()) {
    cout << "IMPOSSIBLE" << "\n";
  } else if(GCD == 1) {
    cout << "POSSIBLE" << "\n";
  } else {
    cout << (K % GCD == 0 ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
  }
  return 0;
}
