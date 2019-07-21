#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void dfs(vector<vector<int> >& Graph, vector<bool>& visited, int v, int k, bool root, ll& ans) {
  visited[v] = true;
  int n = root ? k-1 : k-2;
  for(int i=0; i<Graph[v].size(); i++) {
    int w = Graph[v][i];
    if(!visited[w]) {
      ans = (ans * n) % mod;
      n--;
      dfs(Graph, visited, w, k, false, ans);
    }
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  vector<vector<int> > Graph(N);
  vector<bool> visited(N);

  rep(i, N-1) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    Graph[A[i]].push_back(B[i]);
    Graph[B[i]].push_back(A[i]);
  }
  ll ans = K;
  dfs(Graph, visited, 0, K, true, ans);
  cout << ans << endl;
  return 0;
}

