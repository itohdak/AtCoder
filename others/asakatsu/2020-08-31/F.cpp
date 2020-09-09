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

void ng() {
  cout << -1 << endk;
  exit(0);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  if(s[n-1] == '1') ng();
  if(s[0] == '0') ng();
  rep(i, n-1) if(s[i] != s[n-2-i]) ng();
  vector<int> P(n);
  int par = -1;
  rep(i, n) {
    P[i] = par;
    if(i == 0 || s[n-1-i] == '1') par = i;
  }
  rep(i, n) if(i) cout << i+1 << ' ' << P[i]+1 << endk;
  return 0;
}
