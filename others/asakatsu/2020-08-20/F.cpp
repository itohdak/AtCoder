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
  vector<int> A(n);
  map<int, int> mp;
  rep(i, n) {
    cin >> A[i];
    mp[A[i]]++;
  }
  if(mp.size() > 2) {
    cout << "No" << endk;
  } else if(mp.size() == 2) {
    int m = mp.begin()->first;
    int M = mp.rbegin()->first;
    if(M-m>1) cout << "No" << endk;
    else {
      if(mp[m] >= M) cout << "No" << endk;
      else if(mp[M] < (M-mp[m])*2) cout << "No" << endk;
      else cout << "Yes" << endk;
    }
  } else {
    int m = mp.begin()->first;
    if(mp[m] >= m*2 || mp[m]-1 == m) cout << "Yes" << endk;
    else cout << "No" << endk;
  }
  return 0;
}
