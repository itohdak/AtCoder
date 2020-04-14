#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  string S;
  cin >> N >> S;
  vector<ll> cnt(3);
  rep(i, N) {
    if(S[i] == 'R')      cnt[0]++;
    else if(S[i] == 'G') cnt[1]++;
    else                 cnt[2]++;
  }
  ll ans = cnt[0] * cnt[1] * cnt[2];
  rep(i, N) {
    REP(j, i+1, N) {
      int k = 2*j-i;
      if(k<N) {
	if(S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) ans--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
