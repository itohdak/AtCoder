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
  int n, k, c;
  cin >> n >> k >> c;
  string s; cin >> s;
  vector<int> vl(n), vr(n);
  {
    int i = 0;
    int cnt = 1;
    while(i < n && cnt <= k) {
      if(s[i] == 'o') {
        vl[i] = cnt;
        cnt++;
        i += c+1;
      } else {
        i++;
      }
    }
  }
  // cout << vl << endk;
  {
    int i = n-1;
    int cnt = k;
    while(i >= 0 && cnt > 0) {
      if(s[i] == 'o') {
        vr[i] = cnt;
        cnt--;
        i -= c+1;
      } else {
        i--;
      }
    }
  }
  // cout << vr << endk;
  rep(i, n) {
    if(s[i] == 'o' && vl[i] != 0 && vr[i] != 0 && vl[i] == vr[i]) cout << i+1 << endk;
  }
  return 0;
}
