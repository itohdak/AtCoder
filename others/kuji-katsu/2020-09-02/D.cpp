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
  vector<string> A(h);
  map<char, int> cnt;
  rep(i, h) {
    cin >> A[i];
    rep(j, w) cnt[A[i][j]]++;
  }
  int n4=0, n2=0, n1=0;
  for(auto ele: cnt) {
    if(ele.second % 4 == 0) n4++;
    else if(ele.second % 4 == 1) n1++;
    else if(ele.second % 4 == 2) n2++;
    else if(ele.second % 4 == 3) {
      n1++;
      n2++;
    }
  }
  if(h%2==0 && w%2==0) {
    if(n1 || n2) cout << "No" << endk;
    else cout << "Yes" << endk;
  } else if(h%2==0) {
    if(n1 || n2 > h/2) cout << "No" << endk;
    else cout << "Yes" << endk;
  } else if(w%2==0) {
    if(n1 || n2 > w/2) cout << "No" << endk;
    else cout << "Yes" << endk;
  } else {
    if(n1 != 1 || n2 > w/2+h/2) cout << "No" << endk;
    else cout << "Yes" << endk;
  }
  return 0;
}
