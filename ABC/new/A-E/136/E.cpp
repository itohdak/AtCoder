#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  ll sum = accumulate(A.begin(), A.end(), 0LL);
  find_divisor(sum);
  int M = divisor.size();
  vector<ll> R(N);
  vector<ll> S(N+1);
  rep(i, M) {
    ll div = divisor[M-i-1];
    rep(i, N) R[i] = A[i] % div;
    sort(R.begin(), R.end());
    rep(i, N) S[i+1] = S[i] + R[i];
    ll m = longinf;
    REP(i, 1, N) m = min(m, max(S[i], div*(N-i)-(S[N]-S[i])));
    if(m <= K) {
      cout << div << endl;
      break;
    }
  }
  return 0;
}

