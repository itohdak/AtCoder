#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
// template<class t, class u>
// ostream& operator<<(ostream& os, const pair<t, u>& p) {
//   return os << "{" << p.first << ", " << p.second << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
//   os << "{";
//   rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
//   return os << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const set<t>& se) {
//   os << "{";
//   auto itr = se.begin();
//   rep(i, se.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
// template<class t, class u>
// ostream& operator<<(ostream& os, const map<t, u>& mp) {
//   os << "{";
//   auto itr = mp.begin();
//   rep(i, mp.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  priority_queue<ll> ALL;
  {
    priority_queue<ll> P;
    rep(i, A) {
      ll p;
      cin >> p;
      P.push(p);
    }
    rep(i, X) {
      ALL.push(P.top());
      P.pop();
    }
  }
  {
    priority_queue<ll> Q;
    rep(i, B) {
      ll q;
      cin >> q;
      Q.push(q);
    }
    rep(i, Y) {
      ALL.push(Q.top());
      Q.pop();
    }
  }
  rep(i, C) {
    ll r;
    cin >> r;
    ALL.push(r);
  }
  ll ans = 0;
  rep(i, X+Y) {
    ans += ALL.top();
    ALL.pop();
  }
  cout << ans << endl;
  return 0;
}

