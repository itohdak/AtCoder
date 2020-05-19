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
  string S;
  cin >> S;
  int N = S.size();
  vector<int> B(N);
  rep(i, N) rep(j, N) B[j] += (S[i]=='o')<<((i+j)%N);
  // rep(i, N) cout << bitset<5>(B[i]) << endl;
  int ans = inf;
  rep(i, 1<<N) {
    int b = 0;
    int cnt = 0;
    rep(j, N) if(i&(1<<j)) {
      cnt++;
      b|=B[j];
    }
    if(b == (1<<N)-1) ans = min(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}
