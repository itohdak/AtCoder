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
  int k; cin >> k;
  string s; cin >> s;
  map<pair<int, int>, vector<pair<int, int>>> next;
  int x = 0, y = 0;
  auto update = [&](int x, int y) {
    rep(i, 4) {
      auto ne = next[{x, y}][i];
      if(!next.count(ne)) {
        next[ne] = {{ne.first-1, ne.second},
                    {ne.first, ne.second+1},
                    {ne.first+1, ne.second},
                    {ne.first, ne.second-1}};
      }
    }
    // cout << next << endk;
    rep(i, 4) {
      auto ne1 = next[{x, y}][i];
      auto ne2 = next[{x, y}][(i+2)%4];
      next[ne2][i] = ne1;
    }
    // cout << next << endk;
  };
  next[{0, 0}] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  char d[] = {'L', 'U', 'R', 'D'};
  for(char c: s) {
    update(x, y);
    rep(i, 4) {
      if(c == d[i]) {
        auto ne = next[{x, y}][i];
        x = ne.first;
        y = ne.second;
      }
    }
    // cout << x << ' ' << y << endk;
  }
  cout << x << ' ' << y << endk;
  return 0;
}
