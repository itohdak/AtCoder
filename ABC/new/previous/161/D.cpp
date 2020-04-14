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
  int K;
  cin >> K;
  vector<set<ll> > vse(12);
  rep(j, 9) vse[1].insert(j+1);
  REP(i, 2, 11) {
    for(ll v: vse[i-1]) {
      int tmp = v % 10;
      if(tmp != 0) vse[i].insert(v*10+tmp-1);
      vse[i].insert(v*10+tmp);
      if(tmp != 9) vse[i].insert(v*10+tmp+1);
    }
  }
  int tmp = 1;
  while(K > 0) {
    if(K > vse[tmp].size()) {
      K -= vse[tmp].size();
      tmp++;
    } else {
      auto itr = vse[tmp].begin();
      rep(i, K-1) itr++;
      cout << *itr << endl;
      break;
    }
  }
  return 0;
}

