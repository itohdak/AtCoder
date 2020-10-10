#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  vector<pair<int, int>> P(n);
  vector<int> id(n);
  rep(i, n) {
    cin >> P[i].first >> P[i].second;
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return P[i] < P[j];
  });
  vector<int> A(n);
  rep(i, n) A[i] = P[id[i]].second;
  // cout << A << endk;
  dsu uf(n);
  map<int, int> mp;
  rrep(i, n) {
    auto itr = mp.lower_bound(A[i]);
    if(itr != mp.end()) {
      vector<pair<int, int>> tmp;
      for(; itr!=mp.end(); itr++) {
        uf.merge(id[i], itr->second);
        tmp.push_back(*itr);
      }
      for(auto p: tmp) mp.erase(p.first);
      mp[tmp.back().first] = tmp.back().second;
    } else {
      mp[A[i]] = id[i];
    }
  }
  vector<int> ans(n);
  rep(i, n) {
    ans[id[i]] = uf.size(id[i]);
  }
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
