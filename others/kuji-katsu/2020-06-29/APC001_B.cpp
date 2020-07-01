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
  vector<ll> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  ll t = accumulate(all(B), 0LL) - accumulate(all(A), 0LL);
  if(t < 0) {
    cout << "No\n";
    return 0;
  }
  // -1 only B : cnt
  // +2 only A : cnt
  // +1 both A and B : t-cnt
  ll cnt = 0;
  rep(i, N) {
    if(A[i] > B[i]) cnt += A[i]-B[i];
    else if(A[i]%2 != B[i]%2) cnt++;
  }
  cout << (cnt>t ? "No\n" : "Yes\n");
  return 0;
}
