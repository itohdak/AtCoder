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
  vector<ll> A(3*n); rep(i, 3*n) cin >> A[i];
  vector<ll> mx(n+1), mn(n+1);
  mx[0] = accumulate(begin(A), begin(A)+n, 0LL);
  mn[n] = accumulate(begin(A)+2*n, end(A), 0LL);
  {
    priority_queue<ll, vector<ll>, greater<ll>> q;
    rep(i, n) q.push(A[i]);
    REP(i, n, 2*n) {
      ll in = A[i]; q.push(in);
      ll out = q.top(); q.pop();
      mx[i-n+1] = mx[i-n]+in-out;
    }
  }
  {
    priority_queue<ll> q;
    REP(i, 2*n, 3*n) q.push(A[i]);
    for(int i=2*n-1; i>=n; i--) {
      ll in = A[i]; q.push(in);
      ll out = q.top(); q.pop();
      mn[i-n] = mn[i-n+1]+in-out;
    }
  }
  ll ans = -longinf;
  rep(i, n+1) ans = max(mx[i]-mn[i], ans);
  cout << ans << "\n";
  return 0;
}
