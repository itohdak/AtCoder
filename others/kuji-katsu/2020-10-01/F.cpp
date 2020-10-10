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
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
  }
  vector<int> path;
  vector<int> curPath;
  vector<bool> inPath(n);
  vector<bool> vis(n);
  bool loop = false;
  auto dfs = [&](auto dfs, int cur) -> void {
    if(loop) return;
    if(inPath[cur]) {
      loop = true;
      auto itr = find(all(path), cur);
      int sz = path.end() - itr;
      curPath = vector<int>(sz);
      copy(itr, path.end(), curPath.begin());
      return;
    }
    if(vis[cur]) return;
    vis[cur] = true;
    inPath[cur] = true;
    path.push_back(cur);
    for(int ne: G[cur]) {
      dfs(dfs, ne);
      if(loop) return;
    }
    inPath[cur] = false;
    path.pop_back();
  };
  rep(i, n) {
    rep(j, n) inPath[j] = false;
    dfs(dfs, i);
  }
  if(!loop) cout << -1 << "\n";
  else {
    bool updated = true;
    // cout << curPath << endl;
    while(updated) {
      updated = false;
      set<int> se;
      for(int v: curPath) se.insert(v);
      int sz = curPath.size();
      rep(i, sz) {
        int v = curPath[i];
        for(int ne: G[v]) {
          if(se.count(ne) && ne!=curPath[(i+1)%sz]) {
            // cout << curPath << endl;
            // cout << v << " -> " << ne << endl;
            vector<int> newCurPath;
            int j = find(all(curPath), ne) - begin(curPath);
            while(j != i) {
              newCurPath.push_back(curPath[j]);
              (j+=1)%=sz;
            }
            newCurPath.push_back(curPath[j]);
            curPath = vector<int>(newCurPath.size());
            copy(all(newCurPath), begin(curPath));
            updated = true;
          }
          if(updated) break;
        }
        if(updated) break;
      }
    }
    cout << curPath.size() << "\n";
    for(int v: curPath) cout << v+1 << "\n";
  }
  return 0;
}
