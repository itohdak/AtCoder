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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> ans(n);
  rrep(i, n) {
    ll sum = 0;
    for(int j=1; (i+1)*j<=n; j++) {
      sum += ans[(i+1)*j-1];
    }
    if(sum%2 != A[i]) ans[i]++;
  }
  cout << accumulate(all(ans), 0LL) << endk;
  rep(i, n) if(ans[i] == 1) cout << i+1 << endk;
  return 0;
}
