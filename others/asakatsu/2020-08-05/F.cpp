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
  int n; ll x; cin >> n >> x;
  vector<int> T(n); rep(i, n) cin >> T[i];
  vector<ll> A(n); rep(i, n) cin >> A[i];
  map<int, vector<ll>> mp; rep(i, n) mp[T[i]].push_back(A[i]);
  auto bsearch = [&]() {
    auto test = [&](int k) -> bool {
      priority_queue<ll> q;
      for(auto itr=mp.lower_bound(k); itr!=mp.end(); itr++) {
        for(ll a: itr->second) q.push(a);
      }
      ll val = 0;
      for(int i=k; i>0; i--) {
        if(!q.empty()) {
          val += q.top(); q.pop();
        }
        if(mp.count(i-1)) {
          for(ll a: mp[i-1]) q.push(a);
        }
      }
      return val >= x;
    };
    int ok = 100005, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  int res = bsearch();
  cout << (res==100005 ? -1 : res) << endk;
  return 0;
}
