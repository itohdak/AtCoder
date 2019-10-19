#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  priority_queue<ll> q;
  rep(i, N) q.push(A[i]);
  rep(i, M) {
    ll tmp = q.top();
    q.pop();
    q.push(tmp / 2);
  }
  ll ans = 0;
  rep(i, N) {
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
  return 0;
}

