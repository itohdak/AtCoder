#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

vector<vector<ll>> dist;
void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(m), B(m);
  dist = vector<vector<ll>>(n, vector<ll>(n, longinf));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    dist[A[i]][B[i]] = dist[B[i]][A[i]] = 1;
  }
  warshall_floyd(n);
  rep(i, n) {
    int cnt = 0;
    rep(j, n) if(dist[i][j] == 2) cnt++;
    cout << cnt << "\n";
  }
  return 0;
}
