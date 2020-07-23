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
  ll h, w; int n; cin >> h >> w >> n;
  map<pair<ll, ll>, int> mp;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    for(int j=-1; j<=1; j++) {
      for(int k=-1; k<=1; k++) {
        if(a+j<=0 || a+j>=h-1 || b+k<=0 || b+k>=w-1) continue;
        mp[{a+j, b+k}]++;
      }
    }
  }
  vector<ll> cnt(10);
  for(auto ele: mp) cnt[ele.second]++;
  cnt[0] = (h-2)*(w-2) - accumulate(cnt.begin()+1, cnt.end(), 0LL);
  rep(i, 10) cout << cnt[i] << "\n";
  return 0;
}
