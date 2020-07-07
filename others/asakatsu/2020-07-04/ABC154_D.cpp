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
  int n, k; cin >> n >> k;
  vector<ll> P(n); rep(i, n) cin >> P[i];
  cout << fixed << setprecision(20);
  double sum = 0;
  rep(i, k) sum += P[i]*(P[i]+1)/2/(double)P[i];
  double mx = sum;
  for(int i=k; i<n; i++) {
    sum += P[i]*(P[i]+1)/2/(double)P[i] - P[i-k]*(P[i-k]+1)/2/(double)P[i-k];;
    mx = max(sum, mx);
  }
  cout << mx << "\n";
  return 0;
}
