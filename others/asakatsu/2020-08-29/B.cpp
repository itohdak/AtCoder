#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
  vector<int> E(6), L(6);
  set<int> st;
  rep(i, 6) {
    cin >> E[i];
    st.insert(E[i]);
  }
  int b; cin >> b;
  rep(i, 6) cin >> L[i];
  int cnt = 0, cntb = 0;
  // cout << E << L << endk;
  rep(i, 6) {
    if(st.count(L[i])) cnt++;
    else if(L[i] == b) cntb++;
  }
  if(cnt == 6) cout << 1 << endk;
  else if(cnt == 5 && cntb) cout << 2 << endk;
  else if(cnt == 5) cout << 3 << endk;
  else if(cnt == 4) cout << 4 << endk;
  else if(cnt == 3) cout << 5 << endk;
  else cout << 0 << endk;
  return 0;
}
