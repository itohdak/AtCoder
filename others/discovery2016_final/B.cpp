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
  int n; ll x; cin >> n >> x;
  vector<int> T(n); rep(i, n) cin >> T[i];
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, vector<int>> mp;
  rep(i, n) mp[T[i]].push_back(A[i]);
  auto bsearch = [&]() {
    auto test = [&](ll t) {
      ll sum = 0;
      priority_queue<ll> q;
      auto itr = mp.rbegin();
      for(; itr!=mp.rend(); itr++) {
        if(itr->first >= t) {
          for(int a: itr->second) q.push(a);
        } else {
          break;
        }
      }
      while(itr != mp.rend()) {
        while(itr->first < t && !q.empty()) {
          sum += q.top(); q.pop();
          t--;
        }
        t = itr->first;
        for(int a: itr->second) q.push(a);
        itr++;
      }
      while(t && !q.empty()) {
        sum += q.top(); q.pop();
        t--;
      }
      return sum >= x;
    };
    ll ok = longinf, ng = 0;
    while(ok-ng>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll ret = bsearch();
  cout << (ret==longinf ? -1 : ret) << "\n";
  return 0;
}
