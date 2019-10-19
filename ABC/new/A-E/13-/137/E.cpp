#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct Edge {
  int to;
  int cost;
  Edge(int t, int c) : to(t), cost(c) {}
};

typedef vector< vector<Edge> > AdjList;
AdjList graph;
vector<int> dist;
vector<int> par;

bool bellman_ford(int n, int s){ // n: number of edges, s: source
  bool negloop = false;
  dist = vector<int>(n, inf);
  dist[s] = 0;
  for(int i=0; i<n; i++){
    for(int v=0; v<n; v++){
      for(int k=0; k<graph[v].size(); k++){
        Edge e = graph[v][k];
        if(dist[v] != inf && dist[e.to] > dist[v] + e.cost){
          dist[e.to] = dist[v] + e.cost;
          par[e.to] = v;
          if(i == n - 1) {
            dist[e.to] = -inf;
            negloop = true;
          }
        }
      }
    }
  }
  return negloop;
}

vector<int> buildPath(int t) {
  vector<int> path;
  for(int u=t; u>=0; u=par[u])
    path.push_back(u);
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  int N, M, P;
  cin >> N >> M >> P;
  graph = AdjList(N);
  par = vector<int>(N, -1);
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    graph[a].push_back(Edge(b, -(c-P)));
  }
  bool ret = bellman_ford(N, 0);
  if(ret) {
    vector<int> path;
    for(int u=N-1; u>=0&&path.size()<N; u=par[u])
      path.push_back(u);
    reverse(path.begin(), path.end());
    for(int p: path) {
      if(dist[p] == -inf) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << max(0, -dist[N-1]) << endl;
  return 0;
}

