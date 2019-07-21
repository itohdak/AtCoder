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
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  int nMinus = N/2;
  ll ans = accumulate(A.begin()+nMinus, A.end(), 0LL)
    - accumulate(A.begin(), A.begin()+nMinus, 0LL);
  cout << ans << endl;
  ll tmp = 0;
  int start = 0;
  if(N % 2 == 1) tmp = A[N-1];
  else {
    cout << A[nMinus] << ' ' << A[0] << endl;
    tmp = A[nMinus] - A[0];
    start++;
  }
  REP(i, start, nMinus) {
    ll tmp2;
    cout << A[i] << ' ' << A[i+nMinus] << endl;
    tmp2 = A[i] - A[i+nMinus];
    cout << tmp << ' ' << tmp2 << endl;
    tmp -= tmp2;
  }
  return 0;
}

