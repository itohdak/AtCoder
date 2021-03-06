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
  vector<vector<int>> A(h, vector<int>(w));
  vector<pair<int, int>> pos(h*w);
  rep(i, h) rep(j, w) {
    cin >> A[i][j];
    A[i][j]--;
    pos[A[i][j]] = {i, j};
  }
  vector<int> to(h*w);
  vector<bool> ridge(h*w);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, h*w) {
    auto [x, y] = pos[i];
    vector<int> lower;
    bool isRidge = false;
    rep(k, 4) {
      int nx = x+dx[k];
      int ny = y+dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(A[nx][ny] < A[x][y]) {
        lower.push_back(A[nx][ny]);
        isRidge |= ridge[A[nx][ny]];
      }
    }
    if(lower.empty()) {
      to[i] = i;
    } else if(isRidge) {
      ridge[i] = true;
    } else {
      set<int> st;
      for(auto l: lower) st.insert(to[l]);
      if(st.size() > 1) ridge[i] = true;
      else to[i] = *st.begin();
    }
  }
  cout << accumulate(all(ridge), 0) << endk;
  return 0;
}
