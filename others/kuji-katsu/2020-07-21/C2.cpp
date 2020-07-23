#include <bits/stdc++.h>
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
  rep(i, n) REP(j, i, i+k) st.insert(s.substr(i, j-i+1));
  auto itr = st.begin();
  rep(i, k-1) itr++;
  cout << *itr << "\n";
  return 0;
}
