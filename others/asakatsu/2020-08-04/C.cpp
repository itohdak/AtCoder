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
  int n; cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  if(accumulate(all(A), 0LL) < accumulate(all(B), 0LL)) {
    cout << -1 << endk;
  } else {
    priority_queue<ll> q;
    ll need = 0;
    int ans = 0;
    rep(i, n) {
      if(A[i]>B[i]) q.push(A[i]-B[i]);
      else if(A[i]<B[i]) {
        ans++;
        need += B[i]-A[i];
      }
    }
    while(need > 0) {
      need -= q.top(); q.pop();
      ans++;
    }
    cout << ans << endk;
  }
  return 0;
}
