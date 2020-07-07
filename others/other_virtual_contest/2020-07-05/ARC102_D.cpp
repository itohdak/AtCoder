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

struct edge {
  int from;
  int to;
  ll cost;
  edge(int f, int t, ll c): from(f), to(t), cost(c) {};
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll l; cin >> l;
  int r = log2(l);
  int n = r+1;
  vector<edge> E;
  rep(i, r) {
    E.push_back({i, i+1, 0});
    E.push_back({i, i+1, 1LL<<i});
  }
  for(int i=n-2; i>=0; i--) {
    if(l-(1LL<<i) >= 1LL<<r) {
      E.push_back({i, n-1, l-(1LL<<i)});
      l -= (1LL<<i);
    }
  }
  cout << n << ' ' << E.size() << "\n";
  for(auto e: E) cout << e.from+1 << ' ' << e.to+1 << ' ' << e.cost << "\n";
  return 0;
}
