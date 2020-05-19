#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9+7;

int N;
vector<vector<int>> G;
void bfs(int s, vector<ll>& d) {
  d = vector<ll>(N, inf);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(auto to: G[v]) {
      if(d[to] == inf) {
	d[to] = d[v] + 1;
	q.push(to);
      }
    }
  }
}
