#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

struct edge{
  int from;
  int to;
  ll cost;
};

int main(){
  int N;
  cin >> N;
  vector<edge> edges;
  for(int i=0; i<N-1; i++){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    edge e = {a, b, c};
    edges.push_back(e);
  }
  int Q, K;
  cin >> Q >> K;
  K--;
  ll map[N];
  for(int i=0; i<N; i++){
    if(i == K)
      map[i] = 0;
    else
      map[i] = 10000000000;
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<edges.size(); j++){
      edge e = edges[j];
      if(map[e.to] > map[e.from] + e.cost)
	map[e.to] = map[e.from] + e.cost;
      else if(map[e.from] > map[e.to] + e.cost)
	map[e.from] = map[e.to] + e.cost;
    }
  }
  for(int i=0; i<Q; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << map[x] + map[y] << endl;
  }
  return 0;
}

