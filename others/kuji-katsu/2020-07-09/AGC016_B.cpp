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
  map<ll, int> mp;
  vector<ll> A(n);
  rep(i, n) {
    cin >> A[i];
    mp[A[i]]++;
  }
  auto ng = [&]() {
    cout << "No" << "\n";
    exit(0);
  };
  auto ok = [&]() {
    cout << "Yes" << "\n";
    exit(0);
  };
  ll mn = mp.begin()->first;
  ll mx = mp.rbegin()->first;
  ll diff = mx - mn;
  if(diff > 1) ng();
  else if(diff == 1) {
    if(mp[mn]+min(mp[mx]-1, 1) > mx && mp[mx] < mp[mn]-1) ng();
    else ok();
  } else {
    if(mn > n/2 && n-1 != mn) ng();
    else ok();
  }
  return 0;
}
