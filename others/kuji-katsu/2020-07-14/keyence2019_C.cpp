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
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  if(accumulate(all(A), 0LL) < accumulate(all(B), 0LL)) {
    cout << -1 << "\n";
  } else {
    ll tarinai = 0;
    priority_queue<ll> yobun;
    int ans = 0;
    rep(i, n) {
      if(B[i] > A[i]) {
        tarinai += B[i]-A[i];
        ans++;
      } else if(B[i] < A[i]) {
        yobun.push(A[i]-B[i]);
      }
    }
    ll sum = 0;
    while(sum < tarinai) {
      sum += yobun.top(); yobun.pop();
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
