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
  int N, M;
  cin >> N >> M;
  vector<string> S(M);
  vector<ll> B(M), C(M);
  rep(i, M) {
    cin >> S[i] >> C[i];
    rep(j, N) B[i] += ((S[i][j]=='Y')<<j);
  }
  vector<ll> dp(1<<N, longinf);
  dp[0] = 0;
  repl(i, M) repl(j, 1<<N) dp[j|B[i]] = min(dp[j]+C[i], dp[j|B[i]]);
  cout << (dp[(1<<N)-1] == longinf ? -1 : dp[(1<<N)-1]) << endl;
  return 0;
}
