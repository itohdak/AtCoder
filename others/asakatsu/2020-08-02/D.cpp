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
  string s; cin >> s;
  int n = s.size();
  int l = 0;
  ll ans = 0;
  while(l < n) {
    while(l < n && s[l] != '2') l++;
    int r = l;
    while(r < n && s[r] == ((r-l)%2 ? '5' : '2')) r++;
    ll m = (r-l)/2;
    ans += (m+1)*m/2;
    l = r;
  }
  cout << ans << "\n";
  return 0;
}
