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
  vector<pair<int, ll>> P(n);
  rep(i, n) {
    P[i].first = T[i];
    P[i].second = A[i];
  }
  sort(all(P), [&](pair<int, ll> p1, pair<int, ll> p2) {
      return p1 < p2;
    });
  auto bsearch = [&]() {
    auto test = [&](ll k) {
      priority_queue<ll> q;
      int ib = lower_bound(all(P), pair<int, ll>(k-1, 0)) - begin(P);
      for(int i=ib; i<n; i++) q.push(P[i].second);
      ll sum = 0;
      for(int i=k-1; i>=0; i--) {
        if(!q.empty()) {
          sum += q.top(); q.pop();
        }
        while(ib-1>=0 && P[ib-1].first == i) {
          q.push(P[ib-1].second);
          ib--;
        }
      }
      return sum >= x;
    };
    int ok = 100005, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  int ret = bsearch();
  cout << (ret==100005 ? -1 : ret) << endk;
  return 0;
}
