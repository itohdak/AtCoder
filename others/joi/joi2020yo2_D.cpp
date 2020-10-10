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
  int m, r; cin >> m >> r;
  vector<vector<int>> cost(10, vector<int>(10));
  rep(i, 10) REP(j, i, 10) {
    if(i == 0) {
      if(i == j) cost[i][j] = 0;
      else cost[i][j] = cost[j][i] = (j-1)/3+1 + (j-1)%3;
    } else {
      if(i == j) cost[i][j] = 0;
      else cost[i][j] = cost[j][i] = abs(i/3-j/3) + abs(i%3-j%3);
    }
  }
  auto calc = [&](ll r) {
    ll res = 0;
    ll pre = -1;
    while(r) {
      if(pre != -1) res += cost[pre][r%10];
      pre = r%10;
      if(r < 10) res += cost[r][0];
      r /= 10;
      res++;
    }
    return res;
  };
  return 0;
}
