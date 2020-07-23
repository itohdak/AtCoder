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
  int n; cin >> n;
  vector<int> H(n); rep(i, n) cin >> H[i];
  int ans = 0;
  while(1) {
    int cnt = 0;
    bool flag = false;
    rep(i, n) {
      if(flag && H[i]<=0) {
        cnt++; flag = false;
      } else if(!flag && H[i]>0) {
        flag = true;
      }
    }
    if(flag) cnt++;
    if(cnt) {
      ans += cnt;
      rep(i, n) H[i]--;
    } else {
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}
