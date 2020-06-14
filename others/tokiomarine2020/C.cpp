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
  ll N, K;
  cin >> N >> K;
  vector<vector<ll>> A(2, vector<ll>(N+1));
  rep(i, N) cin >> A[0][i];
  int flag = 1;
  bool ok;
  rep(k, K) {
    rep(i, N+1) A[flag][i] = 0;
    rep(i, N) {
      ll l = max(i-A[1-flag][i], 0LL);
      ll r = min(i+A[1-flag][i], N-1);
      A[flag][l]++;
      A[flag][r+1]--;
    }
    ok = true;
    rep(i, N) A[flag][i+1] += A[flag][i];
    rep(i, N) if(A[flag][i] != N) ok = false;
    if(ok) break;
    flag = 1-flag;
  }
  if(ok) rep(i, N) cout << N << ' ';
  else rep(i, N) cout << A[1-flag][i] << ' ';
  cout << endl;
  return 0;
}
