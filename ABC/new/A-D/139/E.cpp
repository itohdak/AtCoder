#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void dfs(vector<vector<int> >& B, int tmp, int len, vector<bool>& vis, vector<bool>& vis2, bool& flag, vector<int>& depth) {
  if(flag) return;
  if(B[tmp].empty()) {
    depth[tmp] = max(depth[tmp], 1);
  } else {
    for(auto ne: B[tmp]) {
      if(vis[ne]) {
        if(vis2[ne]) flag = true;
        depth[tmp] = max(depth[tmp], depth[ne]+1);
      } else {
        vis[ne] = true;
        vis2[ne] = true;
        dfs(B, ne, len+1, vis, vis2, flag, depth);
        depth[tmp] = max(depth[tmp], depth[ne]+1);
        vis2[ne] = false;
      }
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > mp(N, vector<int>(N));
  {
    int cnt = 0;
    rep(i, N) {
      REP(j, i+1, N) {
        mp[i][j] = cnt;
        mp[j][i] = cnt;
        cnt++;
      }
    }
  }
  vector<vector<int> > A(N, vector<int>(N-1));
  int M = N*(N-1)/2;
  vector<vector<int> > B(M), C(M);
  rep(i, N) {
    int prev;
    rep(j, N-1) {
      cin >> A[i][j];
      A[i][j]--;
      int tmp = mp[i][A[i][j]];
      if(j > 0) {
        B[prev].push_back(tmp);
        C[tmp].push_back(prev);
      }
      prev = tmp;
    }
  }
  bool flag = false;
  vector<bool> vis(M);
  vector<int> depth(M);
  rep(i, C.size()) {
    if(!vis[i]) {
      vis[i] = true;
      vector<bool> vis2(M);
      vis2[i] = true;
      dfs(B, i, 1, vis, vis2, flag, depth);
    }
  }
  int ans = -1;
  rep(i, M)
    ans = max(ans, depth[i]);
  if(flag)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}

