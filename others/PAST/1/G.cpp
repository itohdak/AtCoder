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

vector<vector<int>> ve;
int N;
ll ans;
vector<vector<ll>> A;
void dfs(int tmp) {
  if(tmp == N) {
    ll tmp = 0;
    rep(i, 3) rep(j, ve[i].size()) REP(k, j+1, ve[i].size()) tmp += A[ve[i][j]][ve[i][k]];
    ans = max(tmp, ans);
    return;
  }
  rep(i, 3) {
    ve[i].push_back(tmp);
    dfs(tmp+1);
    ve[i].pop_back();
  }
}
int main() {
  cin >> N;
  A = vector<vector<ll>>(N, vector<ll>(N));
  rep(i, N) REP(j, i+1, N) {
    cin >> A[i][j];
    A[j][i] = A[i][j];
  }
  ve = vector<vector<int>>(3);
  ans = -longinf;
  dfs(0);
  cout << ans << endl;
  return 0;
}
