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
  int h, w; cin >> h >> w;
  vector<int> cnt(26);
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) cnt[s[j]-'a']++;
  }
  int cnt2=0, cnt4=0, cntOdd=0;
  rep(i, 26) {
    cntOdd += cnt[i]%2;
    cnt4 += cnt[i]/4;
    cnt2 += cnt[i]%4/2;
  }
  // cout << cntOdd << ' ' << cnt4 << ' ' << cnt2 << endk;
  if(h%2==0 && w%2==0) {
    if(cntOdd || cnt2) cout << "No" << endk;
    else cout << "Yes" << endk;
  } else if(h%2==0) {
    if(cntOdd || cnt2 > h/2) cout << "No" << endk;
    else cout << "Yes" << endk;
  } else if(w%2==0) {
    if(cntOdd || cnt2 > w/2) cout << "No" << endk;
    else cout << "Yes" << endk;
  } else {
    if(cntOdd != 1 || cnt2 > w/2+h/2) cout << "No" << endk;
    else cout << "Yes" << endk;
  }
  return 0;
}
