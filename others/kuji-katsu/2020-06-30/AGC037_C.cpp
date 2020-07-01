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
  vector<ll> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  priority_queue<pair<ll, int>> q;
  rep(i, N) q.push({B[i], i});
  ll ans = 0;
  while(!q.empty()) {
    auto ele = q.top(); q.pop();
    ll val = ele.first;
    int i = ele.second;
    if(val-A[i] < B[(i+N-1)%N]+B[(i+1)%N]) continue;
    ll rem = (val-A[i])%(B[(i+N-1)%N]+B[(i+1)%N]);
    ll cur = (val-A[i])/(B[(i+N-1)%N]+B[(i+1)%N]);
    ans += cur;
    B[i] = A[i]+rem;
    if(rem) q.push({B[i], i});
  }
  bool ok = true;
  rep(i, N) if(A[i] != B[i]) ok = false;
  cout << (ok ? ans : -1) << endl;
  return 0;
}
