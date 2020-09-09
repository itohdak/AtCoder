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
  int n; cin >> n;
  map<ll, int> mp;
  vector<ll> A(n);
  rep(i, n) {
    cin >> A[i];
    mp[A[i]]++;
  }
  // xi == xi+3
  if(n % 3 == 0) {
    if(mp.size() > 3) cout << "No" << endk;
    else if(mp.size() == 3) {
      bool ok = true;
      ll sum = 0;
      for(auto ele: mp) {
        sum ^= ele.first;
        if(ele.second != n/3) ok = false;
      }
      if(ok && sum==0) cout << "Yes" << endk;
      else cout << "No" << endk;
    } else if(mp.size() == 2) {
      // x 0 x x 0 x
      if(mp.count(0) && mp[0] == n/3) cout << "Yes" << endk;
      else cout << "No" << endk;
    } else {
      if(mp.count(0)) cout << "Yes" << endk;
      else cout << "No" << endk;
    }
  } else {
    if(mp.size() == 1 && mp.count(0)) cout << "Yes" << endk;
    else cout << "No" << endk;
  }
  return 0;
}
