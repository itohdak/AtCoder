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
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<ll> A(n), B(n);
  ll d = ((ll)1e+9-20005) / (n-1);
  rep(i, n) {
    A[i] = B[n-1-i] = 1+d*i;
  }
  rep(i, n) {
    P[i]--;
    B[P[i]] += i;
  }
  rep(i, n) cout << A[i] << ' '; cout << endk;
  rep(i, n) cout << B[i] << ' '; cout << endk;
  return 0;
}
