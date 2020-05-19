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
  int N;
  cin >> N;
  vector<vector<int>> D(N, vector<int>(N));
  vector<vector<ll>> sum(N+1, vector<ll>(N+1));
  rep(i, N) rep(j, N) {
    cin >> D[i][j];
    sum[i+1][j+1] = D[i][j];
  }
  rep(i, N) rep(j, N) sum[i+1][j+1] += sum[i+1][j];
  rep(j, N) rep(i, N) sum[i+1][j+1] += sum[i][j+1];
  // cout << sum << endl;
  int Q;
  cin >> Q;
  rep(q, Q) {
    int p;
    cin >> p;
    ll ans = 0;
    for(int h=1; h<=min(p, N); h++) {
      int w = min(p/h, N);
      rep(i, N) rep(j, N) {
        if(i+h>N || j+w>N) continue;
        ll tmp = sum[i+h][j+w]-sum[i+h][j]-sum[i][j+w]+sum[i][j];
        ans = max(tmp, ans);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
