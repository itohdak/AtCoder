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
  ll k; cin >> k;
  // 0 1 2 3 ... n-1
  // n 0 1 2 ... n-2
  // [n-1]
  // 1 2 3 4 ... n
  int n = 50;
  cout << n << "\n";
  ll base = k/50;
  ll rem = k%50;
  rep(i, n+1) if(i != n-rem) cout << base+i << " ";
  cout << "\n";
  return 0;
}
