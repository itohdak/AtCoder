#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string dirString[] = {
    "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
    "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
  double deg, dis;
  cin >> deg >> dis;
  double dir = deg/10;
  string dirAns = dirString[((int)floor((dir-11.25)/22.5)+1)%16];
  int bf = round(dis/60*10);
  int bfClass[] = {
    3, 16, 34, 55,
    80, 108, 139, 172,
    208, 245, 285, 327};
  vector<int> bfVec(bfClass, bfClass+12);
  int bfAns = upper_bound(all(bfVec), bf) - bfVec.begin();
  cout << (bfAns==0 ? "C" : dirAns) << ' ' << bfAns << endl;
  return 0;
}
