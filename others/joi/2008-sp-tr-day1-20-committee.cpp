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
  vector<int> S(n), A(n);
  vector<vector<int>> G(n);
  rep(i, n) {
    cin >> S[i] >> A[i];
    S[i]--;
    if(S[i] != -1) G[S[i]].push_back(i);
  }
  int ans = -inf;
  auto dfs = [&](auto dfs, int cur) -> int {
    int sum = A[cur];
    for(int ne: G[cur]) {
      sum += max(0, dfs(dfs, ne));
    }
    chmax(ans, sum);
    return sum;
  };
  dfs(dfs, 0);
  cout << ans << endk;
  return 0;
}
