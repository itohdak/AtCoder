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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<int> next(N, -1);
  vector<int> topN(N);
  rep(i, N) {
    topN[i] = i;
    next[i] = 1e6+i;
  }
  rep(i, Q) {
    int f, t, x;
    cin >> f >> t >> x;
    --f, --t, --x;
    int tmp = topN[f];
    topN[f] = next[x];
    next[x] = topN[t];
    topN[t] = tmp;
  }
  vector<int> ans(N);
  rep(i, N) {
    set<int> se;
    int tmp = topN[i];
    while(tmp < 1e6) {
      se.insert(tmp);
      tmp = next[tmp];
    }
    for(auto s: se) ans[s] = tmp-1e6+1;
  }
  rep(i, N) cout << ans[i] << endl;
  return 0;
}
