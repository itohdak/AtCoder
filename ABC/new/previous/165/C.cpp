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

int V[11][11][11];
vector<int> v;
int N, M;
ll ans;
void dfs(int tmp) {
  if(tmp == N) {
    ll point = 0;
    rep(i, N) REP(j, i+1, N) point += V[i+1][j+1][v[j]-v[i]];
    if(point > ans) {
      ans = max(point, ans);
      // cout << v << ' ' << ans << endl;
      // point = 0;
      // rep(i, N) REP(j, i+1, N) {
      //   point += V[i+1][j+1][v[j]-v[i]];
      //   if(V[i+1][j+1][v[j]-v[i]] != 0) cout << i+1 << ' ' << j+1 << ' ' << V[i+1][j+1][v[j]-v[i]] << ' ' << point << endl;
      // }
    }
    return;
  }
  int begin = (tmp ? (*--v.end()) : 1);
  REP(i, begin, M+1) {
    v.push_back(i);
    dfs(tmp+1);
    v.pop_back();
  }
}
int main() {
  int Q;
  cin >> N >> M >> Q;
  rep(i, 11) rep(j, 11) rep(k, 11) V[i][j][k] = 0;
  vector<int> A(Q), B(Q), C(Q), D(Q);
  rep(i, Q) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    V[A[i]][B[i]][C[i]] = max(D[i], V[A[i]][B[i]][C[i]]);
  }
  ans = 0;
  dfs(0);
  cout << ans << endl;
  return 0;
}
