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
  vector<vector<int>> B(2, vector<int>(3));
  vector<vector<int>> C(3, vector<int>(2));
  rep(i, 2) rep(j, 3) cin >> B[i][j];
  rep(i, 3) rep(j, 2) cin >> C[i][j];
  vector<vector<int>> board(3, vector<int>(3, -1));
  auto dfs = [&](auto dfs, int turn) -> vector<int> {
    if(turn == 9) {
      vector<int> point = {0, 0};
      rep(i, 2) rep(j, 3) {
        point[(board[i][j] != board[i+1][j])] += B[i][j];
      }
      rep(i, 3) rep(j, 2) {
        point[(board[i][j] != board[i][j+1])] += C[i][j];
      }
      return point;
    }
    vector<int> mx = {-1, -1};
    pair<int, int> mxPos;
    rep(i, 3) rep(j, 3) {
      if(board[i][j] == -1) {
        board[i][j] = turn%2;
        auto ret = dfs(dfs, turn+1);
        if(ret[turn%2] > mx[turn%2]) {
          mx = ret;
          mxPos = {i, j};
        }
        board[i][j] = -1;
      }
    }
    return mx;
  };
  auto ans = dfs(dfs, 0);
  cout << ans[0] << "\n" << ans[1] << "\n";
  return 0;
}
