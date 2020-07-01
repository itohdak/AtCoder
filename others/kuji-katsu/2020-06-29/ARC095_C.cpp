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
  int N;
  cin >> N;
  vector<ll> X(N);
  rep(i, N) cin >> X[i];
  vector<ll> Xcopy(N);
  copy(all(X), begin(Xcopy));
  sort(all(Xcopy));
  ll m1 = Xcopy[N/2-1], m2 = Xcopy[N/2];
  rep(i, N) cout << (X[i]<m2 ? m2 : m1) << "\n";
  return 0;
}
