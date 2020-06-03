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
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  sort(all(A));
  sort(all(B));
  double l, r;
  if(N % 2 == 0) {
    l = (A[N/2-1]+A[N/2])/2.0;
    r = (B[N/2-1]+B[N/2])/2.0;
    cout << (ll)((r-l)*2.0)+1 << endl;
  } else {
    l = A[N/2];
    r = B[N/2];
    cout << (ll)(r-l)+1 << endl;
  }
  return 0;
}
