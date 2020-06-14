#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> col(N, -1);
  vector<vector<int>> group(2);
  function<void(int, int)> dfs = [&](int tmp, int par) {
    col[tmp] = (par==-1 ? 0 : 1-col[par]);
    group[col[tmp]].push_back(tmp);
    for(int ne: G[tmp]) {
      if(ne != par) dfs(ne, tmp);
    }
  };
  dfs(0, -1);
  vector<int> ans(N);
  if((int)group[0].size() > N/3 && (int)group[1].size() > N/3) {
    int tmp = 1;
    int tmp2 = 3;
    for(int i: group[0]) {
      if(tmp <= N) {
        ans[i] = tmp;
        tmp += 3;
      } else {
        ans[i] = tmp2;
        tmp2 += 3;
      }
    }
    tmp = 2;
    for(int i: group[1]) {
      if(tmp <= N) {
        ans[i] = tmp;
        tmp += 3;
      } else {
        ans[i] = tmp2;
        tmp2 += 3;
      }
    }
  } else {
    int small = ((int)group[0].size() > (int)group[1].size());
    int tmp = 3;
    for(int i: group[small]) {
      ans[i] = tmp;
      tmp += 3;
    }
    int tmp2 = 1;
    for(int i: group[1-small]) {
      if(tmp <= N) {
        ans[i] = tmp;
        tmp += 3;
      } else {
        ans[i] = tmp2;
        tmp2++;
        if(tmp2 % 3 == 0) tmp2++;
      }
    }
  }
  rep(i, N) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
