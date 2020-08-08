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
  int n; ll c; cin >> n >> c;
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, int> odd, even;
  rep(i, n) {
    if(i%2) odd[A[i]]++;
    else    even[A[i]]++;
  }
  vector<pair<int, int>> cntOdd, cntEven;
  cntOdd.push_back({0, 11});
  cntEven.push_back({0, 11});
  for(auto ele: odd) cntOdd.push_back({ele.second, ele.first});
  for(auto ele: even) cntEven.push_back({ele.second, ele.first});
  sort(all(cntOdd), greater<pair<int, int>>());
  sort(all(cntEven), greater<pair<int, int>>());
  if(cntOdd[0].second == cntEven[0].second) {
    int mx = max(cntOdd[0].first+cntEven[1].first,
                 cntOdd[1].first+cntEven[0].first);
    cout << (n-mx)*c << endk;
  } else {
    cout << (n-cntOdd[0].first-cntEven[0].first)*c << endk;
  }
  return 0;
}
