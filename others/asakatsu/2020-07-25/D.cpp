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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  ll mx = accumulate(all(B), 0LL) - accumulate(all(A), 0LL);
  ll cnt1 = 0, cnt2 = 0;
  rep(i, n) if(A[i]<B[i]) {
    cnt2 += (B[i]-A[i])/2;
    if((B[i]-A[i])%2) cnt2++, cnt1++;
    A[i] = B[i];
  }
  rep(i, n) if(A[i]>B[i]) {
    cnt1 += A[i]-B[i];
    B[i] = A[i];
  }
  cout << (cnt2<=mx&&cnt1<=mx ? "Yes" : "No") << "\n";
  return 0;
}
