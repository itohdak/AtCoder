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
  int Q;
  cin >> Q;
  deque<pair<char, int>> que;
  rep(q, Q) {
    int t;
    cin >> t;
    if(t == 1) {
      char c;
      int x;
      cin >> c >> x;
      que.emplace_back(c, x);
    } else {
      // cout << que << endl;
      int d;
      cin >> d;
      map<char, ll> cnt;
      while(d>0 && !que.empty()) {
        auto& f = que.front();
        if(f.second > d) {
          f.second -= d;
          cnt[f.first] += d;
          d = 0;
        } else {
          d -= f.second;
          cnt[f.first] += f.second;
          que.pop_front();
        }
      }
      // cout << cnt << endl;
      ll ans = 0;
      for(auto m: cnt) ans += m.second * m.second;
      cout << ans << endl;
    }
  }
  return 0;
}
