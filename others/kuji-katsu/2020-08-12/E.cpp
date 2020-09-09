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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> A(h); rep(i, h) cin >> A[i];
  auto bfs = [&]() {
               int dx[] = {-1, 0, 1, 0};
               int dy[] = {0, 1, 0, -1};
               queue<int> q;
               vector<vector<int>> D(h, vector<int>(w, inf));
               vector<vector<bool>> vis(h, vector<bool>(w));
               rep(i, h) rep(j, w) {
                 if(A[i][j] == '#') {
                   q.push(i*w+j);
                   D[i][j] = 0;
                 }
               }
               while(!q.empty()) {
                 auto tmp = q.front(); q.pop();
                 int x = tmp/w;
                 int y = tmp%w;
                 if(vis[x][y]) continue;
                 vis[x][y] = true;
                 rep(k, 4) {
                   int nx = x+dx[k];
                   int ny = y+dy[k];
                   if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                   if(!vis[nx][ny] && D[nx][ny] > D[x][y]+1) {
                     D[nx][ny] = D[x][y]+1;
                     q.push(nx*w+ny);
                   }
                 }
               }
               int ret = 0;
               rep(i, h) ret = max(*max_element(all(D[i])), ret);
               return ret;
             };
  cout << bfs() << endk;
  return 0;
}
