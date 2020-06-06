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
  ll x;
  cin >> N >> x;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<vector<ll>> C(N, vector<ll>(N, longinf));
  rep(i, N) rep(d, N) {
    if(d) C[i][(i+d)%N] = min(C[i][(i+d-1)%N], C[i][(i+d)%N]);
    else  C[i][i] = A[i];
  }
  rep(j, N) rep(d, N) {
    if(d) C[(j+N-d)%N][j] = min(C[(j+N-d+1)%N][j], C[(j+N-d)%N][j]);
  }
  // cout << C << endl;
  ll mn = longinf;
  rep(d, N) {
    ll tmp = x * d;
    rep(j, N) {
      tmp += C[(j+N-d)%N][j];
    }
    mn = min(tmp, mn);
  }
  cout << mn << endl;
  return 0;
}
