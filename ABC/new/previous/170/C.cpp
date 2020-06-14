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
  int X, N;
  cin >> X >> N;
  vector<int> P(N);
  set<int> se;
  rep(i, N) {
    cin >> P[i];
    se.insert(P[i]);
  }
  int r = X;
  while(r <= 101 && se.count(r)) r++;
  int l = X;
  while(l >= 0 && se.count(l)) l--;
  if(abs(r-X) >= abs(l-X)) {
    cout << l << endl;
  } else {
    cout << r << endl;
  }
  return 0;
}
