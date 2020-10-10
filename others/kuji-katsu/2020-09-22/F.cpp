#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n);
  priority_queue<pair<ll, int>> q;
  rep(i, n) {
    cin >> A[i];
    q.push({A[i], i});
  }
  q.push({0, -1});
  vector<ll> ans(n);
  int cnt = 0;
  int mn = inf;
  while(!q.empty()) {
    auto top = q.top(); q.pop();
    cnt++;
    ll cur = top.first;
    if(cur == 0) break;
    chmin(mn, top.second);
    while(!q.empty() && q.top().first == cur) {
      chmin(mn, q.top().second);
      cnt++;
      q.pop();
    }
    auto next = q.top();
    ll diff = (cur - next.first) * cnt;
    ans[mn] += diff;
  }
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
