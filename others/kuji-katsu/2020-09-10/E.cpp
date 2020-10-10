#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/templates/print.hpp"
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  // 2*(sum[j+1]-sum[i]) > j-i+1;
  // 2*sum[j+1]-(j+1) > 2*sum[i]-i;
  vector<vector<int>> sum(26, vector<int>(n+1));
  rep(i, 26) rep(j, n) {
    sum[i][j+1] = sum[i][j] + (s[j] == 'a'+i);
  }
  rep(i, 26) rep(j, n+1) {
    sum[i][j] *= 2;
    sum[i][j] -= j;
  }
  // cout << sum << endk;
  rep(i, 26) {
    set<pair<int, int>> st;
    rep(j, n+1) {
      if(!st.empty() && st.begin()->first < sum[i][j]) {
        cout << st.begin()->second+1 << ' ' << j << endk;
        return 0;
      }
      if(j-1>=0) st.insert({sum[i][j-1], j-1});
    }
  }
  cout << -1 << ' ' << -1 << endk;
  return 0;
}
