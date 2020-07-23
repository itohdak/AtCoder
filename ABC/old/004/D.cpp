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
  int r, g, b; cin >> r >> g >> b;
  ll ans = longinf;
  auto count = [&](int l, int r, int m) -> ll {
    if(r < m) {
      int mn = m-r, mx = m-l, n = r-l+1;
      return (mn+mx)*n/2;
    } else if(l < m) {
      return (m-l)*(m-l+1)/2 + (r-m)*(r-m+1)/2;
    } else {
      int mn = l-m, mx = r-m, n = r-l+1;
      return (mn+mx)*n/2;
    }
  };
  auto countAll = [&](int i, int j, int k) {
    ll cur = 0;
    cur += count(i, i+r-1, -100);
    cur += count(j, j+g-1, 0);
    cur += count(k, k+b-1, 100);
    return cur;
  };
  for(int j=-2000; j<=2000; j++) {
    ll cur = count(j, j+g-1, 0);
    ll mn = longinf;
    for(int i=-2000; i<=j-r; i++) {
      mn = min(count(i, i+r-1, -100), mn);
    }
    cur += mn;
    mn = longinf;
    for(int k=j+g; k<=2000; k++) {
      mn = min(count(k, k+b-1, 100), mn);
    }
    cur += mn;
    ans = min(cur, ans);
  }
  // for(int i=-100-(r-1); i<=-100; i++) {
  //   for(int j=-(g-1); j<=0; j++) {
  //     for(int k=100-(b-1); k<=100; k++) {
  //       if(i+r > j || i+r > k || j+g > k) continue;
  //       ans = min(countAll(i, j, k), ans);
  //     }
  //   }
  // }
  // for(int i=-100-(r+g-1); i<=0; i++) {
  //   for(int k=100-(b-1); k<=100; k++) {
  //     if(i+r+g > k) continue;
  //     int j = i+r;
  //     ans = min(countAll(i, j, k), ans);
  //   }
  // }
  // for(int i=-100-(r-1); i<=-100; i++) {
  //   for(int j=-(g+b-1); j<=100; j++) {
  //     if(i+r > j) continue;
  //     int k = j+g;
  //     ans = min(countAll(i, j, k), ans);
  //   }
  // }
  // for(int i=-100-(r+g+b-1); i<=100; i++) {
  //   int j = i+r, k = j+g;
  //   ans = min(countAll(i, j, k), ans);
  // }
  cout << ans << "\n";
  return 0;
}
