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
  int h, w, K; cin >> h >> w >> K;
  vector<string> s(h); rep(i, h) cin >> s[i];
  int ans = inf;
  rep(i, 1<<(h-1)) {
    map<int, int> mp;
    int cur = 0;
    rep(j, h-1) {
      mp[j] = cur;
      if((i>>j)&1) cur++;
    }
    mp[h-1] = cur;
    int n = cur+1;
    vector<int> cnt(n);
    int tmp = 0;
    bool ok = true;
    rep(j, w) rep(k, h) {
      if(s[k][j] == '1') {
        if(++cnt[mp[k]] > K) {
          tmp++;
          cnt = vector<int>(n);
          rep(k, h) {
            if(s[k][j] == '1') {
              if(++cnt[mp[k]] > K) {
                ok = false;
                j = w;
              }
            }
          }
          break;
        }
      }
    }
    if(!ok) continue;
    // cout << i << ' ' << mp << ' ' << tmp+n-1 << "\n";
    ans = min(ans, tmp+n-1);
  }
  cout << ans << "\n";
  return 0;
}
