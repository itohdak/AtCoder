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
  int a, b; cin >> a >> b;
  set<int> P, Q;
  rep(i, a) {
    int p; cin >> p;
    P.insert(p);
  }
  rep(i, b) {
    int p; cin >> p;
    Q.insert(p);
  }
  vector<char> ans(10);
  rep(i, 10) {
    if(P.count(i)) ans[i] = '.';
    else if(Q.count(i)) ans[i] = 'o';
    else ans[i] = 'x';
  }
  cout << ans[7] << ' ' << ans[8] << ' ' << ans[9] << ' ' << ans[0] << endk;
  cout << ' ' << ans[4] << ' ' << ans[5] << ' ' << ans[6] << endk;
  cout << "  " << ans[2] << ' ' << ans[3] << endk;
  cout << "   " << ans[1] << endk;
  return 0;
}
