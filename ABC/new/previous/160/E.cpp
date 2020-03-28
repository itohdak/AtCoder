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
  vector<ll> P(A), Q(B), R(C);
  rep(i, A) cin >> P[i];
  rep(i, B) cin >> Q[i];
  rep(i, C) cin >> R[i];
  priority_queue<pair<ll, int> > S;
  rep(i, B) S.push(make_pair(Q[i], 0));
  rep(i, C) S.push(make_pair(R[i], 1));
  vector<ll> ret(B+C+1);
  int cnt = 0, cntQ = 0;
  while(!S.empty()) {
    auto top = S.top();
    S.pop();
    if(top.second == 0) {
      cntQ++;
      if(cntQ > Y) continue;
    }
    cnt++;
    ret[cnt] = ret[cnt-1] + top.first;
  }
  sort(all(P), greater<ll>());
  vector<ll> Ps(A+1);
  rep(i, A) Ps[i+1] = Ps[i] + P[i];
  ll ans = 0;
  rep(i, min(A+1, X+1)) {
    if(X+Y-i < B+C+1) ans = max(Ps[i] + ret[X+Y-i], ans);
  }
  cout << ans << endl;
  return 0;
}

