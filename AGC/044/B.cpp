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
  vector<int> P(N*N);
  rep(i, N*N) {
    cin >> P[i];
    P[i]--;
  }
  vector<bool> done(N*N);
  vector<int> D(N*N);
  rep(i, N) rep(j, N) D[i*N+j] = min({i, N-1-i, j, N-1-j});
  ll ans = 0;
  auto bfs = [&](int s) {
    // cout << s << endl;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      int x = cur/N;
      int y = cur%N;
      // cout << cur << endl;
      rep(k, 4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        int ne = nx*N+ny;
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(D[cur]+(!done[cur]) < D[ne]) {
          // cout << "add " << ne << endl;
          q.push(ne);
          D[ne] = D[cur]+(!done[cur]);
        }
      }
    }
  };
  rep(i, N*N) {
    ans += D[P[i]];
    done[P[i]] = true;
    bfs(P[i]);
    // rep(j, N) {rep(k, N) {
    //     cout << D[j*N+k] << ' ';
    //   }
    //   cout << "\n";
    // }
    // cout << endl;
  }
  cout << ans << "\n";
  return 0;
}
