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
  vector<string> S(N);
  vector<vector<bool>> alph(N, vector<bool>(26));
  rep(i, N) {
    cin >> S[i];
    for(char c: S[i]) alph[i][int(c-'a')] = true;
  }
  vector<char> ans(N);
  rep(i, (N+1)/2) {
    bool ok = false;
    rep(j, 26) {
      if(alph[i][j] && alph[N-1-i][j]) {
        ans[i] = ans[N-1-i] = char('a'+j);
        ok = true;
        break;
      }
    }
    if(!ok) {
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i, N) cout << ans[i];
  cout << endl;
  return 0;
}
