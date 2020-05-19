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
  int N, M, X;
  cin >> N >> M >> X;
  vector<vector<int>> A(N, vector<int>(M));
  vector<int> C(N);
  rep(i, N) {
    cin >> C[i];
    rep(j, M) cin >> A[i][j];
  }
  ll ans = longinf;
  rep(i, 1<<N) {
    vector<ll> B(N);
    ll cost = 0;
    rep(j, N) {
      if(i&1<<j) {
        rep(k, M) B[k] += A[j][k];
        cost += C[j];
      }
    }
    bool ok = true;
    rep(k, M) if(B[k] < X) ok = false;
    if(ok) ans = min(cost, ans);
  }
  cout << (ans == longinf ? -1 : ans) << endl;
  return 0;
}
