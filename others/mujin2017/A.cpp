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
  vector<ll> X(n); rep(i, n) cin >> X[i];
  deque<ll> q;
  ll ans = 1;
  rep(i, n) {
    q.push_back(X[i]);
    int m = q.size();
    if(q.back() < 2*m-1) {
      (ans *= m) %= mod;
      q.pop_back();
    }
  }
  int m = q.size();
  for(int i=1; i<=m; i++) (ans *= i) %= mod;
  cout << ans << "\n";
  return 0;
}
