#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int dx = tx - sx;
  int dy = ty - sy;
  rep(i, abs(dx)) cout << (dx > 0 ? 'R' : 'L');
  rep(i, abs(dy)) cout << (dy > 0 ? 'U' : 'D');
  rep(i, abs(dx)) cout << (dx < 0 ? 'R' : 'L');
  rep(i, abs(dy)) cout << (dy < 0 ? 'U' : 'D');
  cout << (dy > 0 ? 'D' : 'U');
  rep(i, abs(dx)+1) cout << (dx > 0 ? 'R' : 'L');
  rep(i, abs(dy)+1) cout << (dy > 0 ? 'U' : 'D');
  cout << (dx > 0 ? 'L' : 'R');
  cout << (dy < 0 ? 'D' : 'U');
  rep(i, abs(dx)+1) cout << (dx < 0 ? 'R' : 'L');
  rep(i, abs(dy)+1) cout << (dy < 0 ? 'U' : 'D');
  cout << (dx < 0 ? 'L' : 'R');
  cout << endl;
  return 0;
}

