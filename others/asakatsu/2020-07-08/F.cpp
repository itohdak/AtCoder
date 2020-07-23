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
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q1;
  priority_queue<pair<ll, ll>> q2;
  rep(i, n) {
    cin >> A[i] >> B[i];
    if(A[i] < B[i]) q1.emplace(A[i], A[i]-B[i]);
    else            q2.emplace(B[i], B[i]-A[i]);
  }
  ll mx = 0;
  ll cur = 0;
  while(!q1.empty()) {
    auto ele = q1.top(); q1.pop();
    cur += ele.first;
    mx = max(cur, mx);
    cur += ele.second-ele.first;
  }
  while(!q2.empty()) {
    auto ele = q2.top(); q2.pop();
    cur += ele.first-ele.second;
    mx = max(cur, mx);
    cur += -ele.first;
  }
  cout << mx << "\n";
  return 0;
}
