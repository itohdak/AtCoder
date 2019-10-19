#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<ll> T(N), A(N);
  ll tmpT = 1, tmpA = 1;
  rep(i, N) {
    cin >> T[i] >> A[i];
    ll tmp = max(ceil((long double)tmpT / T[i]),
                 ceil((long double)tmpA / A[i]));
    tmpT = tmp * T[i];
    tmpA = tmp * A[i];
  }
  cout << tmpT + tmpA << endl;
  return 0;
}

