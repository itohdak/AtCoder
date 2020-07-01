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
  int a, b;
  cin >> a >> b;
  vector<char> ans(10, 'x');
  rep(i, a) {
    int p;
    cin >> p;
    ans[(--p+10)%10] = '.';
  }
  rep(i, b) {
    int q;
    cin >> q;
    ans[(--q+10)%10] = 'o';
  }
  cout << ans[6] << ' ' << ans[7] << ' ' << ans[8] << ' ' << ans[9] << "\n";
  cout << ' ' << ans[3] << ' ' << ans[4] << ' ' << ans[5] << "\n";
  cout << "  " << ans[1] << ' ' << ans[2] << "\n";
  cout << "   " << ans[0] << "\n";
  return 0;
}
