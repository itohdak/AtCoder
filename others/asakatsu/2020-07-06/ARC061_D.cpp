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
  ll h, w;
  int n;
  cin >> h >> w >> n;
  map<ll, int> mp;
  int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  rep(i, n) {
    ll a, b;
    cin >> a >> b; a--; b--;
    rep(k, 9) {
      int nx = a+dx[k];
      int ny = b+dy[k];
      if(nx < 1 || nx >= h-1 || ny < 1 || ny >= w-1) continue;
      mp[nx*w+ny]++;
    }
  }
  vector<ll> ans(10);
  for(auto ele: mp) {
    ans[ele.second]++;
  }
  ans[0] = (h-2)*(w-2)-accumulate(all(ans), 0);
  rep(i, 10) cout << ans[i] << "\n";
  return 0;
}
