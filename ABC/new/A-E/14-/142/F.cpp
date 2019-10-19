#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

bool dfs(vector<vector<int> >& G, vector<bool>& vis, vector<int>& path, int tmp, int par) {
  if(vis[tmp]) {
    path.push_back(tmp);
    return true;
  }
  vis[tmp] = true;
  for(auto ne: G[tmp]) {
    path.push_back(ne);
    if(dfs(G, vis, path, ne, tmp))
      return true;
    else
      path.pop_back();
  }
  vis[tmp] = false;
  return false;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > G(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
  }
  vector<bool> vis(N);
  vector<int> path;
  rep(i, N) {
    if(!vis[i]) {
      path.push_back(i);
      dfs(G, vis, path, i, -1);
      path.pop_back();
    }
  }
  if(path.empty()) {
    cout << -1 << endl;
  } else {
    vector<unordered_map<int, int> > loop(2);
    for(auto itr=find(path.begin(), path.end(), path.back());
        itr!=path.end()-1;
        itr++)
      loop[0][*itr] = *(itr+1);
    int i = 1;
    while(true) {
      loop[i] = unordered_map<int, int>();
      bool updated = false;
      for(auto l: loop[1-i]) {
        int tmp = l.first;
        int ne = l.second;
        for(auto to: G[tmp]) {
          if(to != ne && loop[1-i].find(to) != loop[1-i].end()) {
            int tmp2 = to;
            loop[i][tmp] = to;
            while(tmp2 != tmp) {
              loop[i][tmp2] = loop[1-i][tmp2];
              tmp2 = loop[1-i][tmp2];
            }
            updated = true;
            break;
          }
        }
        if(updated) break;
      }
      if(!updated) break;
      i = 1 - i;
    }
    cout << loop[1-i].size() << endl;
    for(auto v: loop[1-i])
      cout << v.first+1 << endl;
  }
  return 0;
}

