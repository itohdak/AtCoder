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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  rep(i, N) cin >> X[i] >> Y[i];
  double sum = 0;
  vector<bool> vis(N);
  auto dfs = [&](auto dfs, int cur, double d, int cnt) -> void {
    // cout << string(cnt, ' ') << cur << ' ' << cnt << ' ' << d << endl;
    if(cnt == N-1) {
      sum += d;
      return;
    }
    vis[cur] = true;
    rep(i, N) {
      if(!vis[i]) {
        ll dx = X[i]-X[cur];
        ll dy = Y[i]-Y[cur];
        dfs(dfs, i, d+sqrt(dx*dx+dy*dy), cnt+1);
      }
    }
    vis[cur] = false;
  };
  rep(i, N) dfs(dfs, i, 0, 0);
  for(int i=1; i<=N; i++) sum /= i;
  cout << fixed << setprecision(20) << sum << "\n";
  return 0;
}
