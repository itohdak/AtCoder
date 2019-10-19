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
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  sort(L.begin(), L.end());
  ll ans = 0;
  rep(i, N) {
    rep(j, i) {
      int k = (L.begin()+j) - lower_bound(L.begin(), L.begin()+j, L[i]-L[j]+1);
      // cout << L[i] << L[j] << k << endl;
      ans += k;
    }
  }
  cout << ans << endl;
  return 0;
}

