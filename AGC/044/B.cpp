#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> cost(N*N);
  rep(i, N*N) cost[i] = min({i/N, N-1-i/N, i%N, N-1-i%N});
  vector<bool> seated(N*N, true);
  auto bfs = [&](int i, int val) {
    queue<int> q;
    q.push(i);
    vector<bool> vis(N*N);
    cost[i] = 0;
    seated[i] = false;
    while(!q.empty()) {
      int tmp = q.front();
      q.pop();
      vis[tmp] = true;
      if(seated[tmp]) continue;
      seated[i] = false;
      if(cost[tmp] <= val) continue;
      cost[tmp] = val;
      if(tmp/N>0 && !vis[tmp-N]) q.push(tmp-N);
      if(tmp/N<N-1 && !vis[tmp+N]) q.push(tmp+N);
      if(tmp%N>0 && !vis[tmp-1]) q.push(tmp-1);
      if(tmp%N<N-1 && !vis[tmp+1]) q.push(tmp+1);
    }
  };
  int ans = 0;
  rep(i, N*N) {
    int p;
    cin >> p;
    --p;

    cout << p+1 << ' ' << cost[p] << endl;
    rep(j, N) {
      rep(k, N) cout << cost[j*N+k] << ' ';
      cout << endl;
    }
    cout << endl;

    ans += cost[p];
    bfs(p, cost[p]);
  }
  cout << ans << endl;
  return 0;
}
