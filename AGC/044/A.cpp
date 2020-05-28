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

void solve() {
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  ll p[] = {2, 3, 5};
  ll c[] = {A, B, C, D};
  priority_queue<ll> q;
  map<ll, ll> mp;
  q.push(N);
  mp[N] = 0;
  while(!q.empty()) {
    ll tmp = q.top();
    q.pop();
    // cout << tmp << endl;
    rep(i, 3) {
      ll ne = tmp/p[i];

      if(!mp.count(ne)) {
        mp[ne] = longinf;
        q.push(ne);
      }
      mp[ne] = min(mp[tmp]+(tmp-ne*p[i])*c[3]+c[i], mp[ne]);

      if(!mp.count(ne+1)) {
        mp[ne+1] = longinf;
        q.push(ne+1);
      }
      mp[ne+1] = min(mp[tmp]+((ne+1)*p[i]-tmp)*c[3]+c[i], mp[ne+1]);

      mp[ne+1] = min(mp[ne]+c[3], mp[ne+1]);
      mp[ne] = min(mp[ne+1]+c[3], mp[ne]);

      if(mp[tmp]+(tmp-q.top())*c[3] > 0) mp[q.top()] = min(mp[tmp]+(tmp-q.top())*c[3], mp[q.top()]);
    }
  }
  // cout << mp << endl;
  cout << mp[0] << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
