#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  set<int> st;
  rep(i, 6) {
    int e; cin >> e;
    st.insert(e);
  }
  int b; cin >> b;
  set<int> st2;
  rep(i, 6) {
    int l; cin >> l;
    st2.insert(l);
  }
  int cnt = 0;
  int other = -1;
  for(int l: st2) {
    if(st.count(l)) cnt++;
    else other = l;
  }
  if(cnt == 6) {
    cout << 1 << endk;
  } else if(cnt == 5) {
    if(other == b) cout << 2 << endk;
    else cout << 3 << endk;
  } else if(cnt == 4) {
    cout << 4 << endk;
  } else if(cnt == 3) {
    cout << 5 << endk;
  } else {
    cout << 0 << endk;
  }
  return 0;
}
