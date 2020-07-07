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
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  vector<int> D(N+1);
  rep(i, N) D[i+1] = D[i]+L[i];
  cout << upper_bound(all(D), X) - begin(D) << "\n";
  return 0;
}
