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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  deque<int> ans;
  ans.push_back(0);
  ans.push_back(G[0][0]);
  set<int> se;
  se.insert(0); se.insert(G[0][0]);
  auto eval = [&](int i) {
    for(int ne: G[i]) {
      if(se.count(ne)) continue;
      ans.push_back(ne);
      se.insert(ne);
      return false;
    }
    return true;
  };
  auto eval2 = [&](int i) {
    for(int ne: G[i]) {
      if(se.count(ne)) continue;
      ans.push_front(ne);
      se.insert(ne);
      return false;
    }
    return true;
  };
  while(!eval(*(--end(ans)))) {}
  while(!eval2(*(begin(ans)))) {}
  cout << ans.size() << endl;
  for(int a: ans) cout << a+1 << ' ';
  cout << endl;
  return 0;
}
