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
  vector<ll> A(n);
  vector<pair<ll, int>> B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i].second >> B[i].first;
  sort(all(A));
  sort(all(B), greater<pair<ll, int>>());
  int j = 0;
  rep(i, n) {
    if(j >= m) break;
    if(A[i] >= B[j].first) break;
    A[i] = B[j].first;
    B[j].second--;
    if(B[j].second == 0) j++;
  }
  cout << accumulate(all(A), 0LL) << "\n";
  return 0;
}
