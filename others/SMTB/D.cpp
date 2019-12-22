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
  int N;
  cin >> N;
  string S;
  cin >> S;
  map<char, int> mpl, mpr;
  rep(i, N) {
    if(!mpr.count(S[i])) mpr[S[i]] = 0;
    mpr[S[i]]++;
  }
  set<string> se;
  rep(i, N) {
    char tmp = S[i];
    mpr[tmp]--;
    if(mpr[tmp] == 0) mpr.erase(tmp);
    for(auto ml: mpl) {
      for(auto mr: mpr) {
        string cand = "   ";
        cand[0] = ml.first;
        cand[1] = tmp;
        cand[2] = mr.first;
        se.insert(cand);
      }
    }
    if(!mpl.count(tmp)) mpl[tmp] = 0;
    mpl[tmp]++;
  }
  cout << se.size() << endl;
  return 0;
}

