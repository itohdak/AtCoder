#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<ll> dist;
bool bellman_ford(int n, int s, vector<vector<ll>>& cost) {
  dist = vector<ll>(n, longinf);
  dist[s] = 0;
  rep(i, n) {
    rep(j, n) {
      rep(k, n) {
        if(j != k && dist[j] != longinf && dist[k] > dist[j] + cost[j][k]) {
          dist[k] = dist[j] + cost[j][k];
          if(i == n-1) return true;
        }
      }
    }
  }
  return false;
}

void print_cost(int n, int s) {
  cout << endl;
  for(int i=0; i<n; i++) {
    if(i != s) cout << "Cost from " << s << " to " << i << ": " << dist[i] << endl;
  }
}

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<vector<ll>> cost(n, vector<ll>(n));
  rep(i, m) {
    int from, to;
    ll c;
    cin >> from >> to >> c;
    cost[from][to] = c;
  }

  bellman_ford(n, s, cost);

  print_cost(n, s);

  return 0;
}

