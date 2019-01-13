#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct Edge{
  int to, cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};

typedef vector< vector<Edge> > AdjList;
AdjList graph;

const int INF = 1e+8;

vector<int> dist;

bool bellman_ford(int n, int s){ // n: number of edges, s: source
  dist = vector<int>(n, INF);
  dist[s] = 0;
  for(int i=0; i<n; i++){
    for(int v=0; v<n; v++){
      for(int k=0; k<graph[v].size(); k++){
	Edge e = graph[v][k];
	if(dist[v] != INF && dist[e.to] > dist[v] + e.cost){
	  dist[e.to] = dist[v] + e.cost;
	  if(i == n - 1) return true;
	}
      }
    }
  }
  return false;
}

int main(){
  int n, m;
  cin >> n >> m;
  graph = AdjList(n);
  for(int i=0; i<m; i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back(Edge(to, cost));
  }

  for(int s=0; s<n; s++){
    cout << endl;

    bellman_ford(n, s);

    for(int i=0; i<n; i++)
      if(i != s)
	cout << "Cost from " << s << " to " << i << ": " << dist[i] << endl;
  }

  return 0;
}
