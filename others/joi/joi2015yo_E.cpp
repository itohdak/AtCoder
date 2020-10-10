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
  vector<string> S(h);
  rep(i, h) cin >> S[i];
  vector<vector<int>> cnt(h, vector<int>(w));
  vector<queue<int>> q(2);
  rep(i, h) rep(j, w) {
    for(int di=-1; di<=1; di++) {
      for(int dj=-1; dj<=1; dj++) {
        if(di == 0 && dj == 0) continue;
        if(i+di < 0 || i+di >= h || j+dj < 0 || j+dj >= w) continue;
        if(S[i+di][j+dj] == '.') cnt[i][j]++;
      }
    }
    if(S[i][j] != '.' && cnt[i][j] >= S[i][j]-'0') q[0].push(i*w+j);
  }
  int flag = 0;
  vector<vector<bool>> done(h, vector<bool>(w));
  int ans = 0;
  while(!q[flag].empty()) {
    ans++;
    while(!q[flag].empty()) {
      int cur = q[flag].front(); q[flag].pop();
      int x = cur/w;
      int y = cur%w;
      done[x][y] = true;
      for(int dx=-1; dx<=1; dx++) {
        for(int dy=-1; dy<=1; dy++) {
          if(dx == 0 && dy == 0) continue;
          if(x+dx < 0 || x+dx >= h || y+dy < 0 || y+dy >= w) continue;
          if(S[x+dx][y+dy] != '.' && !done[x+dx][y+dy]) {
            cnt[x+dx][y+dy]++;
            if(cnt[x+dx][y+dy] == S[x+dx][y+dy]-'0') {
              q[1-flag].push((x+dx)*w+(y+dy));
            }
          }
        }
      }
    }
    flag = 1-flag;
  }
  cout << ans << endk;
  return 0;
}
