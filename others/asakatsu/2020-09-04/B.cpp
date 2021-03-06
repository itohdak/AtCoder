#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> ans(6);
  rep(_, n) {
    ld mx, mn; cin >> mx >> mn;
    if(mx >= 35) ans[0]++;
    else if(mx >= 30) ans[1]++;
    else if(mx >= 25) ans[2]++;
    if(mn >= 25) ans[3]++;
    if(mn < 0 && mx >= 0) ans[4]++;
    if(mx < 0) ans[5]++;
  }
  rep(i, 6) {
    if(i) cout << ' ';
    cout << ans[i];
  }
  cout << endk;
  return 0;
}
