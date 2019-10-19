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
  ll A, B;
  cin >> N >> A >> B;
  vector<ll> X(N);
  rep(i, N) cin >> X[i];
  ll ans = 0;
  rep(i, N) {
    if(i == 0) continue;
    ans += min((X[i] - X[i-1]) * A, B);
  }
  cout << ans << endl;
  return 0;
}

