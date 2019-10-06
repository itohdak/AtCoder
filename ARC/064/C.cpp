#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  ll x;
  cin >> N >> x;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> B(N-1);
  rep(i, N-1)
    B[i] = max(0LL, A[i+1] + A[i] - x);
  ll cnt = 0;
  rep(i, N) {
    int b = max(0LL, min(B[i], A[i+1]));
    if(i == 0) {
      A[i] -= B[i] - b;
      cnt += B[i] - b;
    }
    A[i+1] -= b;
    B[i+1] -= b;
    cnt += b;
  }
  cout << cnt << endl;
  return 0;
}

