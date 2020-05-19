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
  string S;
  cin >> S;
  int n = S.size();
  vector<string> T(N);
  vector<vector<int>> id(n);
  rep(i, N) {
    cin >> T[i];
    rep(j, n) {
      if(j+T[i].size()>n) continue;
      bool ok = (S.substr(j, T[i].size()) == T[i]);
      if(ok) id[j+T[i].size()-1].push_back(j);
    }
  }
  // cout << id << endl;
  vector<ll> dp(n+1);
  dp[0] = 1;
  rep(i, n) for(int j: id[i]) (dp[i+1] += dp[j]) %= mod;
  cout << dp[n] << endl;
  return 0;
}
