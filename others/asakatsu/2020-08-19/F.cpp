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
  vector<int> A(n-1), B(n-1);
  vector<vector<int>> G(n);
  rep(i, n-1) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  vector<int> d(n, inf);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
               if(par != -1) chmin(d[cur], d[par]+1);
               for(int ne: G[cur]) if(ne != par) dfs(dfs, ne, cur);
             };
  d[0] = 0;
  dfs(dfs, 0, -1);
  int s = max_element(all(d))-begin(d);
  d = vector<int>(n, inf);
  d[s] = 0;
  dfs(dfs, s, -1);
  int t = max_element(all(d))-begin(d);
  cout << min(s, t)+1 << ' ' << max(s, t)+1 << endk;
  return 0;
}
