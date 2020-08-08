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
  int m; cin >> m;
  vector<ll> D(m), C(m);
  ll ans = 0;
  ll cur = 0;
  rep(i, m) {
    cin >> D[i] >> C[i];
    ll sum = D[i]*C[i];
    ll carry = sum/9-(sum%9==0);
    ll rem = (sum%9==0 ? 9 : sum%9);
    ans += C[i]-(i==0)+carry;
    cur += rem;
    if(cur > 9) {
      ans++;
      cur -= 9;
    }
  }
  cout << ans << "\n";
  return 0;
}
