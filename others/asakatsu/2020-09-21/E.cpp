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
  string s, t; cin >> s >> t;
  set<char> st;
  for(char c: s) st.insert(c);
  for(char c: t) {
    if(!st.count(c)) {
      cout << -1 << endk;
      return 0;
    }
  }
  map<char, set<int>> mp;
  rep(i, s.size()) {
    mp[s[i]].insert(i);
    mp[s[i]].insert(i+s.size());
  }
  ll ans = 0;
  int tmp = -1;
  for(char c: t) {
    int ne = *mp[c].lower_bound(tmp+1);
    ans += ne / s.size() * s.size();
    tmp = ne % s.size();
  }
  cout << ans+tmp+1 << endk;
  return 0;
}