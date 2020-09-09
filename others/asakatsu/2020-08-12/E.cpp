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

ll modpow(ll a, ll N, ll mod) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string x; cin >> x;
  vector<ll> to(n+1);
  rep(i, n+1) {
    if(i) {
      int tmp = i;
      while(tmp) {
        to[i]++;
        tmp %= __builtin_popcount(tmp);
      }
    }
  }
  reverse(all(x));
  int cnt = 0;
  rep(i, n) if(x[i] == '1') cnt++;
  vector<ll> memo(3);
  rep(j, 3) {
    if(cnt-1+j == 0) continue;
    rep(i, n) {
      if(x[i] == '1') (memo[j] += modpow(2, i, cnt-1+j)) %= (cnt-1+j);
    }
  }
  vector<int> ans(n);
  rep(i, n) {
    if(x[i] == '1') {
      if(cnt-1 == 0) {
        ans[i] = 0;
      } else {
        int first = (memo[0]+(cnt-1)-modpow(2, i, cnt-1))%(cnt-1);
        ans[i] = to[first]+1;
      }
    } else {
      int first = (memo[2]+modpow(2, i, cnt+1))%(cnt+1);
      ans[i] = to[first]+1;
    }
  }
  reverse(all(ans));
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
