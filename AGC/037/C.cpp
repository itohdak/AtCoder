#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
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
  priority_queue<pair<ll, int>> Q;
  rep(i, N) Q.emplace(B[i], i);
  ll ans = 0;
  while(!Q.empty()) {
    auto top = Q.top();
    ll b = top.first;
    int i = top.second;
    ll diff = b-A[i];
    Q.pop();
    if(diff >= B[(i-1+N)%N] + B[(i+1)%N]) {
      ans += diff / (B[(i-1+N)%N] + B[(i+1)%N]);
      diff %= B[(i-1+N)%N] + B[(i+1)%N];
      B[i] = A[i]+diff;
      if(diff != 0) Q.emplace(B[i], i);
    } else {
      continue;
    }
  }
  bool ok = true;
  rep(i, N) if(A[i] != B[i]) ok = false;
  cout << (ok ? ans : -1) << endl;
  return 0;
}
