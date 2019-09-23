#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N+1), B(N);
  rep(i, N+1) cin >> A[i];
  rep(i, N) cin >> B[i];
  ll ans = 0;
  rep(i, N) {
    ll def = min(A[i], B[i]);
    ans += def;
    B[i] -= def;
    ll def2 = min(A[i+1], B[i]);
    ans += def2;
    A[i+1] -= def2;
  }
  cout << ans << endl;
  return 0;
}

