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
  vector<ll> A(n);
  vector<bool> diff(n);
  rep(i, n) {
    cin >> A[i];
    if(i) diff[i] = (A[i]-A[i-1]>0);
  }
  // cout << diff << "\n";
  int sum = 0;
  for(int i=1; i<k; i++) sum += diff[i];
  int ans = 0;
  for(int i=k; i<n; i++) {
    if(sum == k-1) ans++;
    sum -= diff[i-(k-1)];
    sum += diff[i];
  }
  if(sum == k-1) ans++;
  cout << ans << "\n";
  return 0;
}
