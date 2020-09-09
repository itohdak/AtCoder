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
  vector<vector<int>> C(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> C[i][j];
  vector<set<string>> vl(13), vr(13);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  {
    string tmp = "";
    rep(i, h) rep(j, w) tmp += char('0'+C[i][j]);
    vl[0].insert(tmp);

    set<string> prev;
    rep(i, 12) {
      for(string s: vl[i]) {
        int pos = find(all(s), '0') - s.begin();
        int x = pos/w;
        int y = pos%w;
        rep(k, 4) {
          int nx = x+dx[k];
          int ny = y+dy[k];
          if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          string t = s;
          int npos = nx*w+ny;
          swap(t[pos], t[npos]);
          if(!prev.count(t)) {
            vl[i+1].insert(t);
            prev.insert(t);
          }
        }
      }
      vl[i+1];
    }
  }
  {
    string tmp = "";
    rep(i, h) rep(j, w) tmp += char('0'+(i*w+j+1)%(h*w));
    vr[0].insert(tmp);

    set<string> prev;
    rep(i, 12) {
      for(string s: vr[i]) {
        int pos = find(all(s), '0') - s.begin();
        int x = pos/w;
        int y = pos%w;
        rep(k, 4) {
          int nx = x+dx[k];
          int ny = y+dy[k];
          if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          string t = s;
          int npos = nx*w+ny;
          swap(t[pos], t[npos]);
          if(!prev.count(t)) {
            vr[i+1].insert(t);
            prev.insert(t);
          }
        }
      }
      vr[i+1];
    }
  }
  int ans = 25;
  rep(i, 13) rep(j, 13) {
    for(auto string: vl[i]) {
      if(vr[j].count(string)) chmin(ans, i+j);
    }
  }
  cout << ans << endk;
  return 0;
}
