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
  int n; cin >> n;
  vector<int> A(n), B(n), C(n-1);
  rep(i, n) cin >> A[i], A[i]--;
  rep(i, n) cin >> B[i];
  rep(i, n-1) cin >> C[i];
  ll ans = accumulate(all(B), 0LL);
  rep(i, n) {
    if(i && A[i-1]+1 == A[i]) ans += C[A[i-1]];
  }
  cout << ans << "\n";
  return 0;
}
