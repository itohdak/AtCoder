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
  int x, y;
  string W;
  cin >> x >> y >> W;
  x--; y--;
  swap(x, y);
  vector<string> S(9);
  rep(i, 9) cin >> S[i];
  map<string, pair<int, int>> mp = {
    {"R", {0, 1}}, {"L", {0, -1}}, {"U", {-1, 0}}, {"D", {1, 0}},
    {"RU", {-1, 1}}, {"RD", {1, 1}},
    {"LU", {-1, -1}}, {"LD", {1, -1}}
  };
  int i = 4;
  string ans = "";
  while(i > 0) {
    int mx, my;
    if(x < 0) mx = -x;
    else if(x >= 9) mx = 16-x;
    else mx = x;
    if(y < 0) my = -y;
    else if(y >= 9) my = 16-y;
    else my = y;
    ans += S[mx][my];
    pair<int, int> d = mp[W];
    x += d.first; y += d.second;
    i--;
  }
  cout << ans << "\n";
  return 0;
}
