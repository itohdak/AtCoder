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
  int h, w, k; cin >> h >> w >> k;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<vector<int>> ans(h, vector<int>(w, -1));
  int tmp = 0;
  rep(i, h) {
    if(S[i] == string(w, '.')) {
      if(i != 0) ans[i] = ans[i-1];
    } else {
      rep(j, w) {
        if(S[i][j] == '#') {
          tmp++;
          while(true) {
            ans[i][j] = tmp;
            j++;
            if(j == w || S[i][j] == '#') break;
          }
          j--;
        }
      }
      int prev = 0;
      rrep(j, w) {
        if(ans[i][j] == -1) ans[i][j] = prev;
        prev = ans[i][j];
      }
    }
  }
  rrep(i, h) {
    if(S[i] == string(w, '.') && i != h-1) {
      ans[i] = ans[i+1];
    }
  }
  rep(i, h) {
    rep(j, w) {
      cout << ans[i][j] << ' ';
    }
    cout << endk;
  }
  return 0;
}
