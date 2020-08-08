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
  ll h, w; int n; cin >> h >> w >> n;
  vector<ll> A(n), B(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  map<pair<ll, ll>, int> mp;
  rep(i, n) {
    for(int j=-1; j<=1; j++) {
      for(int k=-1; k<=1; k++) {
        int a = A[i]+j, b = B[i]+k;
        if(a<=0 || a>=h-1 || b<=0 || b>=w-1) continue;
        mp[{a, b}]++;
      }
    }
  }
  vector<ll> ans(10);
  for(auto ele: mp) {
    ans[ele.second]++;
  }
  ans[0] = (h-2)*(w-2) - accumulate(begin(ans)+1, end(ans), 0LL);
  rep(i, 10) cout << ans[i] << "\n";
  return 0;
}
