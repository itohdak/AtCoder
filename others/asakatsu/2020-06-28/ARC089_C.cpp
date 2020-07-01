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
  int N;
  cin >> N;
  int prevT = 0, prevX = 0, prevY = 0;
  bool ok = true;
  rep(i, N) {
    int t, x, y;
    cin >> t >> x >> y;
    int rem = (t-prevT)-(abs(prevX-x)+abs(prevY-y));
    if(rem<0 || rem%2) ok = false;
    prevT = t; prevX = x; prevY = y;
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
