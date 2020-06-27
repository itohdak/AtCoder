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
  int N, M;
  cin >> N >> M;
  vector<int> ok(N);
  vector<int> cnt(N, 1);
  ok[0] = 1;
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if(ok[x]) {
      if(cnt[x] == 1) ok[x] = 0;
      ok[y] = 1;
    }
    cnt[x]--; cnt[y]++;
  }
  cout << accumulate(all(ok), 0) << "\n";
  return 0;
}
