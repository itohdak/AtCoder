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
  string S;
  cin >> S;
  int cnt = 0;
  int N = S.size();
  rep(i, N/2) if(S[i] != S[N-1-i]) cnt++;
  if(cnt > 1) {
    cout << 25 * N << endl;
  } else if(cnt == 1) {
    cout << 25 * N - 2 << endl;
  } else {
    cout << 25 * (N-N%2) << endl;
  }
  return 0;
}
