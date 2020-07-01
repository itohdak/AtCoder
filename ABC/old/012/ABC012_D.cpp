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
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> dist(N, vector<ll>(N, longinf));
  rep(i, N) dist[i][i] = 0;
  vector<int> A(M), B(M), T(M);
  rep(i, M) {
    cin >> A[i] >> B[i] >> T[i];
    A[i]--; B[i]--;
    dist[A[i]][B[i]] = T[i];
    dist[B[i]][A[i]] = T[i];
  }
  warshall_floyd(N, dist);
  ll mn = longinf;
  rep(i, N) {
    ll mx = 0;
    rep(j, N) if(i != j) mx = max(dist[i][j], mx);
    mn = min(mx, mn);
  }
  cout << mn << "\n";
  return 0;
}
