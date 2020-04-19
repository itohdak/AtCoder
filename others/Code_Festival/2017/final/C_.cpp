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
  vector<int> D(N+1);
  D[0] = 0;
  rep(i, N) cin >> D[i+1];
  sort(all(D));
  vector<int> cnt(24);
  int flag = 0;
  rep(i, N+1) {
    if(flag) {
      cnt[D[i]%24]++;
    } else {
      cnt[(24-D[i])%24]++;
    }
    flag = 1-flag;
  }
  int ans = 24;
  int tmp = 0;
  rep(i, 25) {
    if(cnt[i] > 1) ans = 0;
    if(i) {
      tmp++;
      if(cnt[i%24]) {
	ans = min(tmp, ans);
	tmp = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
