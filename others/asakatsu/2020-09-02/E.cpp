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
  vector<vector<ll>> A(h, vector<ll>(w));
  vector<int> id(h*w);
  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, h*w) id[i] = i;
  sort(all(id), [&](int i, int j) {
    return A[i/w][i%w] < A[j/w][j%w];
  });
  vector<ll> cnt(h*w);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, h*w) {
    int cur = id[i];
    int x = cur/w;
    int y = cur%w;
    rep(k, 4) {
      int nx = x+dx[k];
      int ny = y+dy[k];
      int ne = nx*w+ny;
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(A[nx][ny] > A[x][y]) {
        (cnt[ne] += cnt[cur]+1) %= mod;
      }
    }
  }
  ll ans = 0;
  rep(i, h*w) {
    (ans += cnt[i]+1) %= mod;
  }
  cout << ans << endk;
  return 0;
}
