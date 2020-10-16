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
  int n, m; cin >> n >> m;
  vector<ll> W(n); rep(i, n) cin >> W[i];
  vector<pair<ll, ll>> LV(m);
  ll minV = longinf;
  rep(i, m) {
    cin >> LV[i].first >> LV[i].second;
    chmin(minV, LV[i].second);
  }
  sort(all(LV), [&](pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.second < p2.second;
  });
  vector<ll> L(m), V(m);
  rep(i, m) {
    L[i] = LV[i].first;
    V[i] = LV[i].second;
  }
  vector<ll> mx(m+1);
  rep(i, m) mx[i+1] = max(mx[i], L[i]);
  rep(i, n) {
    if(W[i] > minV) {
      cout << -1 << endk;
      return 0;
    }
  }
  vector<int> id(n); rep(i, n) id[i] = i;
  ll ans = longinf;
  auto solve = [&](vector<int> id) {
    vector<ll> sum(n+1); rep(i, n) sum[i+1] = sum[i]+W[id[i]];
    vector<vector<ll>> d(n, vector<ll>(n));
    rep(i, n) {
      REP(j, i+1, n) {
        int k = upper_bound(all(V), sum[j+1]-sum[i]-1)-begin(V);
        d[i][j] = mx[k];
        // rep(k, m) {
        //   if(sum[j+1]-sum[i] > LV[k].second) chmax(d[i][j], LV[k].first);
        // }
      }
    }
    vector<ll> D(n);
    rep(i, n) {
      REP(j, i+1, n) {
        chmax(D[j], D[i]+d[i][j]);
      }
    }
    chmin(ans, D[n-1]);
  };
  do {
    solve(id);
  } while(next_permutation(all(id)));
  cout << ans << endk;
  return 0;
}
