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

bool ng() {
  cout << -1 << endk;
  exit(0);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<vector<int>> cnt(3, vector<int>(n));
  vector<vector<int>> cntOther(3, vector<int>(n));
  vector<vector<int>> pos(3);
  char c[] = {'J', 'O', 'I'};
  rep(i, n) {
    if(i) {
      rep(j, 3) {
        cnt[j][i] = cnt[j][i-1];
        cntOther[j][i] = cntOther[j][i-1];
      }
    }
    rep(j, 3) {
      if(s[i] == c[j]) {
        cnt[j][i]++;
        pos[j].push_back(i);
      }
      else cntOther[j][i]++;
    }
  }
  int ans = inf;
  rep(i, n) {
    int tmp = 0;
    if(s[i] != 'O') continue;
    auto itr = lower_bound(all(cnt[1]), cnt[1][i]-1+k);
    if(itr == cnt[1].end()) continue;
    int j = itr-cnt[1].begin();
    // 'O'はiからjで確保
    tmp += cntOther[1][j] - cntOther[1][i-1];
    if(cnt[0][i-1] < k) continue;
    if(cnt[2][n-1]-cnt[2][j] < k) continue;
    auto itrJ = lower_bound(all(cnt[0]), cnt[0][i-1]-k+1);
    tmp += cntOther[0][i-1] - cntOther[0][itrJ-cnt[0].begin()-1];
    auto itrI = lower_bound(all(cnt[2]), cnt[2][j]+k);
    tmp += cntOther[2][itrI-cnt[2].begin()] - cntOther[2][j];
    chmin(ans, tmp);
  }
  if(ans == inf) cout << -1 << endk;
  else cout << ans << endk;
  return 0;
}
