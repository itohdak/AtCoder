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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  ll a, b, c; cin >> a >> b >> c;
  ll A[] = {a, b, c};
  vector<ll> L(n); rep(i, n) cin >> L[i];
  ll mn = longinf;
  rep(i, 1<<(2*n)) {
    vector<ll> len(4);
    vector<ll> cnt(4);
    rep(j, n) {
      len[(i>>(2*j))%4] += L[j];
      cnt[(i>>(2*j))%4]++;
    }
    if(len[0]*len[1]*len[2]==0) continue;
    ll tmp = 0;
    rep(j, 3) {
      tmp += (cnt[j]-1) * 10LL;
      tmp += abs(A[j]-len[j]);
    }
    mn = min(tmp, mn);
  }
  cout << mn << "\n";
  return 0;
}
