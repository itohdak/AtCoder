#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> P(n*n);
  rep(i, n*n) {
    cin >> P[i];
    P[i]--;
  }
  vector<int> cost(n*n);
  rep(i, n) rep(j, n) {
    cost[i*n+j] = min({i, n-1-i, j, n-1-j});
  }
  vector<bool> done(n*n);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  auto bfs = [&](int p) {
    queue<int> q;
    // q.push(p);
    int x = p / n;
    int y = p % n;
    rep(k, 4) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      int ne = nx * n + ny;
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      // if(done[ne]) continue;
      if(cost[ne] > cost[p]) {
        cost[ne] = cost[p];
        q.push(ne);
      }
    }
    vector<bool> vis(n*n);
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      int x = cur / n;
      int y = cur % n;
      if(vis[cur]) continue;
      vis[cur] = true;
      rep(k, 4) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        int ne = nx * n + ny;
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(cost[ne] > cost[cur] + !done[cur]) {
          cost[ne] = cost[cur] + !done[cur];
          q.push(ne);
        }
      }
    }
  };
  ll ans = 0;
  rep(i, n*n) {
    ans += cost[P[i]];
    done[P[i]] = true;
    bfs(P[i]);
    // cout << P[i] << ' ' << ans << endk;
    // rep(j, n) {
    //   rep(k, n) cout << cost[j*n+k] << ' ';
    //   cout << endk;
    // }
    // cout << endk;
  }
  cout << ans << endk;
  return 0;
}
