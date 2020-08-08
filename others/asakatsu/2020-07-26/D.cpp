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
  ll n; cin >> n;
  vector<ll> ans;
  auto check = [](ll n, ll val) {
    ll sum = 0;
    while(n) {
      sum += n%10;
      n /= 10;
    }
    return sum == val;
  };
  for(int i=1; i<=18*9; i++) {
    ll rem = n-i;
    if(check(rem, i)) ans.push_back(rem);
  }
  reverse(all(ans));
  cout << ans.size() << "\n";
  for(ll a: ans) cout << a << "\n";
  return 0;
}
