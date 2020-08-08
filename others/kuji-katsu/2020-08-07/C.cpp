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
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, int> mp;
  rep(i, n) mp[A[i]]++;
  vector<int> v;
  for(auto ele: mp) v.push_back(ele.second);
  sort(all(v), greater<int>());
  if(v.size() <= k) cout << 0 << endk;
  else {
    int ans = 0;
    for(int i=k; i<=v.size(); i++) ans += v[i];
    cout << ans << endk;
  }
  return 0;
}
