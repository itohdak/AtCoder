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
  int h, w, k; cin >> h >> w >> k;
  vector<string> S(h); rep(i, h) cin >> S[i];
  int ans = 0;
  rep(i, 1<<h) rep(j, 1<<w) {
    int cnt = 0;
    rep(k, h) rep(l, w) if(S[k][l]=='#'&&(i>>k)&1&&(j>>l)&1) cnt++;
    if(cnt == k) ans++;
  }
  cout << ans << "\n";
  return 0;
}
