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
  int n; cin >> n;
  vector<ll> T(n); rep(i, n) cin >> T[i];
  map<ll, int> mp;
  rep(i, n) mp[T[i]]++;
  ll ans = 1;
  ll sum = 0;
  int rem = n;
  for(auto ele: mp) {
    rep(i, ele.second) {
      (ans *= i+1) %= mod;
      sum += ele.first * rem;
      rem--;
    }
  }
  cout << sum << endk;
  cout << ans << endk;
  return 0;
}
