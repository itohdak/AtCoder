#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <deque>

using namespace std;
#define ll long long

void dfs(vector<int>& color,
	 vector<vector<pair<int, ll> > > connection,
	 int x) {
  deque<int> D;
  color[x] = 0;
  D.push_back(x);
  while(D.size() > 0) {
    int xtmp = D.back();
    D.pop_back();
    for(int i=0; i<connection[xtmp].size(); i++) {
      int nx = connection[xtmp][i].first;
      int w = connection[xtmp][i].second;
      if(color[nx] == -1) {
	color[nx] = w % 2 == 0 ? color[xtmp] : 1 - color[xtmp];
	D.push_back(nx);
      }
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> color(N, -1);
  vector<vector<pair<int, ll> > > connection(N);
  for(int i=0; i<N-1; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    connection[u].push_back(make_pair(v, w));
    connection[v].push_back(make_pair(u, w));
  }
  dfs(color, connection, 0);
  for(int i=0; i<N; i++)
    cout << color[i] << endl;
  return 0;
}

