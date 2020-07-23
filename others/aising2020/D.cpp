#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

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
  int mx = 300005;
  vector<int> memo(mx);
  rep(i, mx) {
    int cur = i;
    int cnt = 0;
    while(cur) {
      int p = __builtin_popcount(cur);
      cur %= p;
      cnt++;
    }
    memo[i] = cnt;
  }
  int one = 0;
  rep(i, n) if(x[i]=='1') one++;
  map<int, int> mp;
  for(int j=max(one-1, 1); j<=one+1; j++) {
    rep(i, n) {
      if(x[i]=='1') (mp[j] += modpow(2, n-1-i, j)) %= j;
    }
  }
  rep(i, n) {
    if(x[i] == '0') {
      int cur = (mp[one+1] + modpow(2, n-1-i, one+1)) % (one+1);
      cout << memo[cur]+1 << "\n";
    } else {
      if(one-1 == 0) {
        cout << 0 << "\n";
      } else {
        int cur = (mp[one-1] + (one-1) - modpow(2, n-1-i, one-1)) % (one-1);
        cout << memo[cur]+1 << "\n";
      }
    }
  }
  return 0;
}
