#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

typedef vector<vector<int> > Matrix;

void warshall_floyd(int n, Matrix& dist) {
  rep(i, n) rep(j, n) rep(k, n)
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

int main() {
  int N, M;
  ll L;
  cin >> N >> M >> L;
  Matrix dist = Matrix(N, vector<int>(N, inf));
  rep(i, N) dist[i][i] = 0;
  rep(i, M) {
    int A, B;
    ll C;
    cin >> A >> B >> C;
    A--, B--;
    dist[A][B] = C;
    dist[B][A] = C;
  }
  warshall_floyd(N, dist);
  Matrix dist2 = Matrix(N, vector<int>(N, inf));
  rep(i, N) dist[i][i] = 0;
  rep(i, N) rep(j, N)
    if(i != j && dist[i][j] <= L)
      dist2[i][j] = 1;
  warshall_floyd(N, dist2);
  int Q;
  cin >> Q;
  rep(i, Q) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    cout << (dist2[s][t] == inf ? -1 : dist2[s][t]-1) << endl;
  }
  return 0;
}

