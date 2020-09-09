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
  string s; cin >> s;
  int n = s.size()+1;
  s = '>' + s + '<';
  vector<int> ans(n);
  rep(i, n) {
    if(s[i] == '>' && s[i+1] == '<') {
      for(int j=i; j<n; j++) {
        chmax(ans[j], j-i);
        if(s[j+1] == '>') break;
      }
      for(int j=i; j>=0; j--) {
        chmax(ans[j], i-j);
        if(s[j] == '<') break;
      }
    }
  }
  // cout << ans << endk;
  cout << accumulate(all(ans), 0LL) << endk;
  return 0;
}
