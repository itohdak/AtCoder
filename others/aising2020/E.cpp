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

void solve() {
  int n; cin >> n;
  vector<ll> K(n), L(n), R(n);
  priority_queue<ll, vector<ll>, greater<ll>> q;
  map<int, vector<int>> mpp, mpm;
  ll ans = 0;
  int np = 0, nm = 0;
  rep(i, n) {
    cin >> K[i] >> L[i] >> R[i];
    K[i]--;
    if(L[i]-R[i]>=0) {
      mpp[K[i]].push_back(i);
      np++;
    } else {
      mpm[n-K[i]-2].push_back(i);
      nm++;
    }
    ans += min(L[i], R[i]);
  }
  rep(i, n) {
    for(int j: mpp[i]) q.push(L[j]-R[j]);
    while((int)q.size() > min(i+1, np)) q.pop();
  }
  while(!q.empty()) {
    ans += q.top(); q.pop();
  }
  rep(i, n) {
    for(int j: mpm[i]) q.push(R[j]-L[j]);
    while((int)q.size() > min(i+1, nm)) q.pop();
  }
  while(!q.empty()) {
    ans += q.top(); q.pop();
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(_, t) solve();
  return 0;
}
