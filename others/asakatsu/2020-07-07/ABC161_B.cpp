#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll sum = accumulate(all(A), 0LL);
  int cnt = 0;
  rep(i, n) {
    if(A[i] >= (sum+4*m-1)/(4*m)) cnt++;
  }
  cout << (cnt >= m ? "Yes" : "No") << "\n";
  return 0;
}
