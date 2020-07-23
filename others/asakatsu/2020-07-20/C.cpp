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
  int n; cin >> n;
  vector<ll> A(n+2); rep(i, n) cin >> A[i+1];
  ll sum = 0;
  rep(i, n+1) sum += abs(A[i+1]-A[i]);
  rep(i, n) {
    cout << sum - abs(A[i+1]-A[i]) - abs(A[i+2]-A[i+1]) + abs(A[i+2]-A[i]) << "\n";
  }
  return 0;
}
