#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/templates/print.hpp"
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
  int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
  vector<ll> P(a), Q(b), R(c);
  rep(i, a) cin >> P[i];
  rep(i, b) cin >> Q[i];
  rep(i, c) cin >> R[i];
  sort(all(P), greater<ll>());
  sort(all(Q), greater<ll>());
  priority_queue<ll> q;
  rep(i, min(a, x)) q.push(P[i]);
  rep(i, min(b, y)) q.push(Q[i]);
  rep(i, c) q.push(R[i]);
  ll ans = 0;
  rep(i, x+y) ans += q.top(), q.pop();
  cout << ans << endk;
  return 0;
}
