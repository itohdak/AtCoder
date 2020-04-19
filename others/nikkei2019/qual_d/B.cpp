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
  cin >> N;
  vector<string> S(3);
  rep(i, 3) cin >> S[i];
  int ans = 0;
  rep(i, N) {
    vector<int> alph(26);
    rep(j, 3) alph[int(S[j][i]-'a')]++;
    int mx = 0;
    rep(j, 26) mx = max(alph[j], mx);
    ans += 3-mx;
  }
  cout << ans << endl;
  return 0;
}
