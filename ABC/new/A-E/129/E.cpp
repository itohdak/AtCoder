#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string L;
  cin >> L;
  int N = L.size();
  ll ans = 1;
  ll pwr = 1;
  vector<ll> A(N);
  A[N-1] = L[N-1] == '0' ? 1 : 3;
  for(int i=N-2; i>=0; i--) {
    if(L[i] == '1')
      A[i] += 2 * A[i+1] + 1 * pwr * 3;
    else
      A[i] += 1 * A[i+1];
    A[i] %= mod;
    pwr *= 3;
    pwr %= mod;
  }
  cout << A[0] % mod << endl;
  return 0;
}

