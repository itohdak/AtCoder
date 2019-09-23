#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

typedef vector<vector<ll> > Matrix;

Matrix d;
void warshall_floyd(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

void dfs(vector<vector<ll> >& D,
         vector<int>& RR,
         vector<bool>& vis,
         int N, int tmp, int par,
         ll cost, int cnt, ll& ans) {
  // cout << string(cnt, ' ') << RR[tmp] << endl;
  cost = par == -1 ? 0 : cost + D[RR[par]][RR[tmp]];
  if(cnt == N) ans = min(ans, cost);
  vis[tmp] = true;
  rep(i, N) {
    if(!vis[i])
      dfs(D, RR, vis, N, i, tmp, cost, cnt+1, ans);
  }
  vis[tmp] = false;
}

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> RR(R);
  rep(i, R) {
    cin >> RR[i];
    RR[i]--;
  }

  d = Matrix(N, vector<ll>(N, longinf));
  rep(i, N) d[i][i] = 0;
  rep(i, M) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    d[a][b] = c;
    d[b][a] = c;
  }

  warshall_floyd(N);

  vector<bool> vis(N);
  ll ans = longinf;
  rep(i, R)
    dfs(d, RR, vis, R, i, -1, 0, 1, ans);
  cout << ans << endl;
  return 0;
}

