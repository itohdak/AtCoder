#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  queue<int> q;
  vector<int> dis(h*w, inf);
  vector<int> vis(h*w);
  q.push(0);
  dis[0] = 0;
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<int> par(h*w);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    int x = cur/w;
    int y = cur%w;
    if(vis[cur]) continue;
    vis[cur] = true;
    rep(k, 4) {
      int nx = x+dx[k];
      int ny = y+dy[k];
      int ne = nx*w+ny;
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(vis[ne]) continue;
      if(S[nx][ny] == '#') continue;
      if(dis[ne] > dis[cur]) {
        dis[ne] = dis[cur]+1;
        par[ne] = cur;
        q.push(ne);
      }
    }
  }
  if(dis[h*w-1] == inf) cout << -1 << endk;
  else {
    set<int> st;
    int tmp = h*w-1;
    while(tmp != 0) {
      st.insert(tmp);
      tmp = par[tmp];
    }
    st.insert(0);
    int ans = 0;
    rep(i, h) rep(j, w) {
      if(!st.count(i*w+j) && S[i][j] == '.') ans++;
    }
    cout << ans << endk;
  }
  return 0;
}
