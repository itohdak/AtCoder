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
  int H, W;
  cin >> H >> W;
  vector<vector<string> > S(H, vector<string>(W));
  int ansi, ansj;
  rep(i, H) rep(j, W) {
    cin >> S[i][j];
    if(S[i][j] == "snuke") ansi=i, ansj=j;
  }
  cout << char('A'+ansj) << 1+ansi << endl;
  return 0;
}
