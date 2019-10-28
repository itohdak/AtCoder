#include <bits/stdc++.h>
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

vector<ll> A, F;
bool test(int n, ll k, ll t) {
  ll need = 0;
  rep(i, n)
    need += max(0LL, (F[i] * A[i] - t + F[i] - 1) / F[i]);
  return need <= k;
}

int binary_search(int n, ll k, ll m) {
  ll l = 0, r = m+1;
  while(r - l > 1) {
    ll mid = (l + r) / 2;
    if(test(n, k, m-mid))
      l = mid;
    else
      r = mid;
  }
  return m-l;
}

int main() {
  int N; ll K;
  cin >> N >> K;
  A = vector<ll>(N);
  F = vector<ll>(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> F[i];
  sort(all(A));
  sort(all(F), greater<ll>());
  ll M = 0;
  rep(i, N) M = max(M, A[i] * F[i]);
  cout << binary_search(N, K, M) << endl;
  return 0;
}

