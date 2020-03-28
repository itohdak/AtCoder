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
  int N, X, Y;
  cin >> N >> X >> Y;
  X--, Y--;
  vector<int> ans(N);
  rep(i, N) {
    REP(j, i+1, N) {
      ll dst = 0;
      if(i < X) {
	if(j < X) {
	  dst = j - i;
	} else if(X <= j && j <= Y) {
	  dst = (X - i) + min(j - X, Y - j + 1);
	} else {
	  dst = (X - i) + 1 + (j - Y);
	}
      } else if(X <= i && i <= Y) {
	if(X <= j && j <= Y) {
	  dst = min(j - i, Y - X + 1 - (j - i));
	} else {
	  dst = min(Y - i, i - X + 1) + (j - Y);
	}
      } else {
	dst = j - i;
      }
      ans[dst]++;
    }
  }
  rep(i, N) if(i) cout << ans[i] << endl;
  return 0;
}

