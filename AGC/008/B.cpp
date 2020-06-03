#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<ll> A(N), sum(N+1), posSum(N+1);
  rep(i, N) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
    posSum[i+1] = posSum[i] + (A[i]>=0 ? A[i] : 0);
  }
  ll mx = -longinf;
  rep(i, N-K+1) {
    mx = max(posSum[i] + (sum[i+K]-sum[i]) + (posSum[N]-posSum[i+K]), mx);
    mx = max(posSum[i] + 0 + (posSum[N]-posSum[i+K]), mx);
  }
  cout << mx << endl;
  return 0;
}
