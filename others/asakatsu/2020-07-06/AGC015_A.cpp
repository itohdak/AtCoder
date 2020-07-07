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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, a, b; cin >> n >> a >> b;
  // a a a ... b
  // b b b ... b
  if(a > b) cout << 0 << "\n";
  else if(n==1 && a!=b) cout << 0 << "\n";
  else cout << b*(n-1)+a-(a*(n-1)+b)+1 << "\n";
  return 0;
}
