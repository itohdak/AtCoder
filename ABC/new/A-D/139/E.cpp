#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

// int main() {
//   int N;
//   cin >> N;
//   vector<vector<int> > A(N, vector<int>(N));
//   vector<vector<int> > C(N, vector<int>(N, inf));
//   vector<vector<int> > ind(N, vector<int>(N));
//   int cnt = 0;
//   for(int i=0; i<N; i++)
//     for(int j=i; j<N; j++) {
//       ind[i][j] = cnt;
//       cnt++;
//     }
//   rep(i, N) {
//     rep(j, N-1)
//       cin >> A[i][j];
//   }
//   return 0;
// }

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

const long long INF = (1ll << 50);
struct graph {
  typedef long long flow_type;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    size_t rev;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst, flow_type capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  flow_type max_flow(int s, int t) {
    vector<int> level(n), iter(n);
    function<int(void)> levelize = [&]() { // foward levelize
      level.assign(n, -1); level[s] = 0;
      queue<int> Q; Q.push(s);
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;
        for (auto &e: adj[u]) {
          if (e.capacity > e.flow && level[e.dst] < 0) {
            Q.push(e.dst);
            level[e.dst] = level[u] + 1;
          }
        }
      }
      return level[t];
    };
    function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t) return cur;
      for (int &i = iter[u]; i < adj[u].size(); ++i) {
        edge &e = adj[u][i], &r = adj[e.dst][e.rev];
        if (e.capacity > e.flow && level[u] < level[e.dst]) {
          flow_type f = augment(e.dst, min(cur, e.capacity - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };
    for (int u = 0; u < n; ++u) // initialize
      for (auto &e: adj[u]) e.flow = 0;

    flow_type flow = 0;
    while (levelize() >= 0) {
      fill(all(iter), 0);
      for (flow_type f; (f = augment(s, INF)) > 0; )
        flow += f;
    }
    return flow;
  }
};

int main() {
  int N;
  cin >> N;
  graph g(N*(N-1)/2 + 2);
  vector<vector<int> > A(N, vector<int>(N));
  vector<bool> flag1(N*(N-1)/2 + 2);
  vector<bool> flag2(N*(N-1)/2 + 2);
  vector<vector<int> > ind(N, vector<int>(N));
  int cnt = 1;
  for(int i=0; i<N; i++)
    for(int j=i+1; j<N; j++) {
      ind[i][j] = cnt;
      cnt++;
    }
  rep(i, N) {
    int u, v;
    rep(j, N-1) {
      cin >> A[i][j];
      A[i][j]--;
      v = ind[min(i, A[i][j])][max(i, A[i][j])];
      if(j > 0) {
        // cout << u << ' ' << v << endl;
        g.add_edge(u, v, 1);
        flag1[u] = true;
        flag2[v] = true;
      }
      u = v;
    }
  }

  REP(i, 1, N*(N-1)/2+1)
    if(!flag1[i] && flag2[i]) {
      g.add_edge(i, N*(N-1)/2+1, 0);
    } else if(flag1[i] && !flag2[i]) {
      g.add_edge(0, i, 0);
    }

  cout << g.max_flow(0, N*(N-1)/2+1) << endl;
  return 0;
}

