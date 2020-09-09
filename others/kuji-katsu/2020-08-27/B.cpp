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
  int n[4];
  rep(i, 4) n[i] = s[i]-'0';
  rep(i, 1<<3) {
    int sum = n[0];
    string ans;
    ans += s[0];
    rep(j, 3) {
      if((i>>j)&1) {
        sum += n[j+1];
        ans += '+';
      } else {
        sum -= n[j+1];
        ans += '-';
      }
      ans += s[j+1];
    }
    if(sum == 7) {
      cout << ans << "=7" << endk;
      return 0;
    }
  }
  return 0;
}
