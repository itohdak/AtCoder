#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void warshall_floyd(int n, vector<vector<ll>>& dist) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];
  vector<vector<ll>> dist(N, vector<ll>(N, longinf));
  rep(i, N) {
    dist[i][i] = 0;
    REP(j, i+1, N) {
      if(S[i][j] == '1') {
        dist[i][j] = dist[j][i] = 1;
      }
    }
  }
  warshall_floyd(N, dist);
  // cout << dist << endl;
  vector<int> parity(N, -1);
  parity[0] = 0;
  bool ok = true;
  rep(i, N) rep(j, N) {
    if(parity[j] == -1) {
      parity[j] = (parity[i] + dist[i][j]) % 2;
    } else {
      if(parity[j] != (parity[i] + dist[i][j]) % 2) ok = false;
    }
  }
  if(ok) {
    ll mx = 0;
    rep(i, N) mx = max(*max_element(all(dist[i])), mx);
    cout << mx+1 << "\n";
  } else {
    cout << -1 << "\n";
  }
  return 0;
}
