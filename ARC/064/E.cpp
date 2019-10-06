#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

double dis(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

bool bellman_ford(vector<double>& dist,
                  vector<vector<double> >& cost,
                  int n, int s){
  dist[s] = 0;
  rep(i, n) {
    rep(j, n) {
      rep(k, n) {
        if(j != k && dist[j] != DBL_MAX && dist[k] > dist[j] + cost[j][k]) {
          dist[k] = dist[j] + cost[j][k];
          if(i == n-1) return true;
        }
      }
    }
  }
  return false;
}

int main() {
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int N;
  cin >> N;
  vector<double> X(N+2), Y(N+2), R(N+2);
  rep(i, N)
    cin >> X[i] >> Y[i] >> R[i];
  X[N] = xs, Y[N] = ys;
  X[N+1] = xt, Y[N+1] = yt;
  vector<vector<double> > cost(N+2, vector<double>(N+2));
  rep(i, N+2) {
    REP(j, i+1, N+2) {
      double c = max(0.0, dis(X[i], Y[i], X[j], Y[j]) - (R[i] + R[j]));
      cost[i][j] = cost[j][i] = c;
    }
  }
  vector<double> dist(N+2, DBL_MAX);
  bellman_ford(dist, cost, N+2, N);
  cout << setprecision(15) << dist[N+1] << endl;
  return 0;
}

