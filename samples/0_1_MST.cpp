#include "header.hpp"

set<int> se;
vector<set<int> > G;
void dfs(int v) {
  se.erase(v);
  int tmp = 0;
  while(!se.empty()) {
    auto itr = se.upper_bound(tmp);
    if(itr == se.end()) break;
    tmp = *itr;
    if(!G[v].count(tmp)) {
      se.erase(tmp);
      dfs(tmp);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  rep(i, N) se.insert(i);
  G = vector<set<int> >(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  int comp = 0;
  rep(i, N) {
    if(se.count(i)) {
      comp++;
      dfs(i);
    }
  }
  cout << comp-1 << endl;
  return 0;
}

// time complexity: O(N + M)
// https://codeforces.com/contest/920/problem/E
// 繋がっていない頂点ペアのリストが渡されて，逆に（繋がっている）連結グラフの個数を求める問題
// https://codeforces.com/contest/1243/problem/D
// コスト1で繋がっている頂点ペアのリストが渡されて（それ以外のペアもコスト0の辺で結ばれている），最小全域木のコストを求める問題

