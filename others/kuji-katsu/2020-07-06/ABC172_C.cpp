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
  int n, m;
  cin >> n >> m;
  ll k;
  cin >> k;
  vector<ll> A(n), B(m), sumA(n+1), sumB(m+1);
  rep(i, n) {
    cin >> A[i];
    sumA[i+1] = sumA[i] + A[i];
  }
  rep(i, m) {
    cin >> B[i];
    sumB[i+1] = sumB[i] + B[i];
  }
  int ans = 0;
  rep(i, n+1) {
    if(sumA[i] > k) break;
    int j = upper_bound(all(sumB), k-sumA[i])-begin(sumB)-1;
    ans = max(i+j, ans);
  }
  cout << ans << "\n";
  return 0;
}
