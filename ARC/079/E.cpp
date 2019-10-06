#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;


int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  ll sum = accumulate(A.begin(), A.end(), 0LL);
  ll cnt = 0;
  rep(k, sum) {
    bool flag = true;
    rep(i, N) {
      ll tmp = floor(1.0 * A[i] / N);
      if(tmp > 0) flag = false;
      rep(j, N) {
        if(i == j) A[j] -= tmp * N;
        else A[j] += tmp;
      }
      cnt += tmp;
    }
    if(flag) break;
  }
  cout << cnt << endl;
  return 0;
}

