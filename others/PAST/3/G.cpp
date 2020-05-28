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
  int N, X, Y;
  cin >> N >> X >> Y;
  int MAX = 501;
  vector<vector<char>> board(MAX, vector<char>(MAX, '.'));
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    board[x+MAX/2][y+MAX/2] = '#';
  }
  int dx[] = {1, 0, -1, 1, -1, 0};
  int dy[] = {1, 1, 1, 0, 0, -1};
  auto bfs = [&]() {
    queue<pair<int, int>> q;
    vector<vector<int>> dis(MAX, vector<int>(MAX, inf));
    q.emplace(MAX/2, MAX/2);
    dis[MAX/2][MAX/2] = 0;
    while(!q.empty()) {
      auto tmp = q.front();
      q.pop();
      int x = tmp.first;
      int y = tmp.second;
      if(x == X+MAX/2 && y == Y+MAX/2) {
        cout << dis[x][y] << endl;
        return true;
      }
      rep(i, 6) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
        if(dis[nx][ny] != inf) continue;
        if(board[nx][ny] == '#') continue;
        dis[nx][ny] = dis[x][y] + 1;
        q.emplace(nx, ny);
      }
    }
    return false;
  };
  if(!bfs()) cout << -1 << endl;
  return 0;
}
