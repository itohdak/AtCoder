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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int k; cin >> k;
  int n = s.size();
  set<string> st;
  rep(i, n) REP(j, i, n) {
    string t = s.substr(i, j-i+1);
    st.insert(t);
    if(st.size()>k && *st.rbegin()==t) {
      st.erase(--st.end()); break;
    } else if(st.size()>k) {
      st.erase(--st.end());
    }
  }
  cout << *st.rbegin() << "\n";
  return 0;
}
