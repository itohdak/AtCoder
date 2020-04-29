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
  int N, x;
  cin >> N >> x;
  if(x == 1 || x == 2*N-1) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    vector<int> ans(2*N-1);
    if(x != 2) {
      ans[N-2] = x-1;
      ans[N-1] = x;
      ans[N]   = x+1;
      ans[N+1] = x-2;
    } else {
      ans[N-2] = x+1;
      ans[N-1] = x;
      ans[N]   = x-1;
      ans[N+1] = x+2;
    }
    int tmp = 1;
    rep(i, 2*N-1) {
      if(i == N-2 || i == N-1 || i == N || i == N+1) continue;
      if((x != 2 && tmp == x-2) ||
	 (x == 2 && tmp == x-1)) tmp += 4;
      ans[i] = tmp;
      tmp++;
    }
    rep(i, 2*N-1) cout << ans[i] << endl;
  }
  return 0;
}
