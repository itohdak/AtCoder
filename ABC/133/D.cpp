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
  ll tmp = 0;
  rep(i, N) {
    if(i % 2 == 0)
      tmp += A[i];
    else
      tmp -= A[i];
  }
  tmp /= 2;
  rep(i, N) {
    cout << 2 * tmp << ' ';
    tmp = A[i] - tmp;
  }
  cout << endl;
  return 0;
}

