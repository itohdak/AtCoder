#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; ll m, r; cin >> n >> k >> m >> r;
  vector<ll> S(n-1);
  rep(i, n-1) cin >> S[i];
  sort(all(S), greater<ll>());
  if(k == n) {
    ll need = max(k*r - accumulate(all(S), 0LL), 0LL);
    cout << (need>m ? -1 : need) << endk;
  } else {
    ll sum = accumulate(begin(S), begin(S)+k, 0LL);
    ll sum2 = accumulate(begin(S), begin(S)+k-1, 0LL);
    if(sum >= k*r) cout << 0 << endk;
    else {
      ll need = k*r - sum2;
      cout << (need>m ? -1 : need) << endk;
    }
  }
  return 0;
}
