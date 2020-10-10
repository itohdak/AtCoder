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
  int w, h; cin >> w >> h;
  vector<ll> P(w); rep(i, w) cin >> P[i];
  vector<ll> Q(h); rep(i, h) cin >> Q[i];
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  rep(i, w) q.push({P[i], 0});
  rep(i, h) q.push({Q[i], 1});
  ll ans = 0;
  int cntW = w+1, cntH = h+1;
  while(!q.empty()) {
    auto cur = q.top(); q.pop();
    if(cur.second == 0) {
      ans += cur.first * cntH;
      cntW--;
    } else {
      ans += cur.first * cntW;
      cntH--;
    }
  }
  cout << ans << endk;
  return 0;
}
