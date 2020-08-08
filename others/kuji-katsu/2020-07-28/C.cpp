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
  ll a, b, c; cin >> a >> b >> c;
  // (a + b + 2 * sqrt(a * b)) < c
  // 2 * sqrt(a*b) < c - a - b
  // 4 * a * b < (c - a - b) ** 2
  if(c-a-b < 0) {
    cout << "No" << "\n";
  } else {
    cout << (4*a*b < (c-a-b)*(c-a-b) ? "Yes" : "No") << "\n";
  }
  return 0;
}
