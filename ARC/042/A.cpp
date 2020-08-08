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
  int n, m; cin >> n >> m;
  vector<int> A(m);
  rep(i, m) cin >> A[i];
  set<int> done;
  rrep(i, m) {
    if(!done.count(A[i])) {
      cout << A[i] << endk;
      done.insert(A[i]);
    }
  }
  rep(i, n) {
    if(!done.count(i+1)) {
      cout << i+1 << endk;
      done.insert(i+1);
    }
  }
  return 0;
}
