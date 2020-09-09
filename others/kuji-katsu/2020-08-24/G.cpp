#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> d(n);
  vector<int> ans(n);
  vector<vector<int>> cnt(2);
  int i=0, j=0, k=1;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(par != -1) d[cur] = d[par]+1;
    cnt[d[cur]%2].push_back(cur);
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
    }
  };
  dfs(dfs, 0, -1);
  if((int)min(cnt[0].size(), cnt[1].size()) <= n/3) {
    set<int> st; rep(i, n) st.insert(i+1);
    int flag = (cnt[0].size() < cnt[1].size());
    for(int ii: cnt[1-flag]) {
      ans[ii] = 3*k;
      k++;
      st.erase(ans[ii]);
    }
    auto itr = st.begin();
    for(int jj: cnt[flag]) {
      ans[jj] = *itr;
      itr++;
    }
  } else {
    for(int ii: cnt[0]) {
      if(3*i+1 <= n) {
        ans[ii] = 3*i+1;
        i++;
      } else {
        ans[ii] = 3*k;
        k++;
      }
    }
    for(int jj: cnt[1]) {
      if(3*j+2 <= n) {
        ans[jj] = 3*j+2;
        j++;
      } else {
        ans[jj] = 3*k;
        k++;
      }
    }
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
