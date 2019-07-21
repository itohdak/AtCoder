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
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> S(N+1);
  rep(i, N)
    S[i+1] = S[i] + A[i];
  int r = 0;
  ll ans = 0;
  rep(l, N+1) {
    while(r < N+1 && S[r] - S[l] < K) r++;
    if(r == N+1 && S[r] - S[l] < K) break;
    ans += N+1-r;
  }
  cout << ans << endl;
  return 0;
}

