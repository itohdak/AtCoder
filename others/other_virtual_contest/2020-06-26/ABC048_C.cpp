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
  ll x;
  cin >> N >> x;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  ll ans = 0;
  REP(i, 1, N) {
    if(A[i-1] > x) {
      ans += A[i-1]-x;
      A[i-1] = x;
    }
    if(A[i-1]+A[i] > x) {
      ans += A[i-1]+A[i]-x;
      A[i] = x-A[i-1];
    }
  }
  cout << ans << "\n";
  return 0;
}
