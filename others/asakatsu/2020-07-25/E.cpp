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

void warshall_floyd(int n, vector<vector<ll>>& dist) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<ll>> A(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];
  vector<vector<ll>> copyA(n, vector<ll>(n));
  rep(i, n) copy(all(A[i]), begin(copyA[i]));
  warshall_floyd(n, copyA);
  bool ok = true;
  rep(i, n) rep(j, n) {
    if(A[i][j] != copyA[i][j]) ok = false;
  }
  if(!ok) cout << -1 << "\n";
  else {
    priority_queue<pair<ll, pair<int, int>>,
                   vector<pair<ll, pair<int, int>>>,
                   greater<pair<ll, pair<int, int>>>> q;
    ll ans = 0;
    rep(i, n) REP(j, i+1, n) q.push(make_pair(A[i][j], make_pair(i, j)));
    vector<vector<ll>> D(n, vector<ll>(n, longinf));
    rep(i, n) D[i][i] = 0;
    while(!q.empty()) {
      auto ele = q.top(); q.pop();
      ll cost = ele.first;
      int i = ele.second.first;
      int j = ele.second.second;
      bool ok = false;
      rep(k, n) {
        if(k != i && k != j &&
           D[i][k]+D[k][j] == cost) ok = true;
      }
      if(!ok) ans += cost;
      D[i][j] = A[i][j];
      D[j][i] = A[i][j];
    }
    cout << ans << "\n";
  }
  return 0;
}
