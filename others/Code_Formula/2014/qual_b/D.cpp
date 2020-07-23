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

ll modpow(ll a, ll N) {
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
  vector<int> A(n+5); rep(i, n) cin >> A[i];
  int l = 0, r = 0;
  ll ans = 1;
  ll cur = 1;
  while(r < n+5) {
    while(r < n+5 && A[r] >= 10) {
      (cur += modpow(10, r-l) * (A[r]%10)) %= mod;
      A[r+1] += A[r] / 10;
      r++;
    }
    (cur += modpow(10, r-l) * (A[r]%10)) %= mod;
    r++;
    (ans *= cur) %= mod;
    l = r;
    cur = 1;
  }
  cout << (ans+mod-1)%mod << "\n";
  return 0;
}
