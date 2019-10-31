#include <bits/stdc++.h>
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
  int N = S.size();
  if(N == 2) {
    if(S[0] == S[1]) cout << 1 << ' ' << 2 << endl;
    else cout << -1 << ' ' << -1 << endl;
    return 0;
  }
  rep(i, N-2) {
    if(S[i] == S[i+1] || S[i] == S[i+2] || S[i+1] == S[i+2]) {
      cout << i+1 << ' ' << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << endl;
  return 0;
}

