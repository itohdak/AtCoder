#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  string s;
  cin >> N >> s;
  vector<int> ans(N);
  char ani[] = {'S', 'W'};
  rep(i, 2) rep(j, 2) {
    ans[0] = i;
    ans[1] = j;
    REP(k, 1, N-1) {
      if(ans[k] == 0) {
        ans[k+1] = (s[k] == 'o' ? ans[k-1] : 1-ans[k-1]);
      } else {
        ans[k+1] = (s[k] == 'x' ? ans[k-1] : 1-ans[k-1]);
      }
    }
    bool ok = true;
    REP(i, N-1, N+1) {
      if(!((s[i%N] == 'o' &&
            ((ans[i%N] == 0 && ans[i-1] == ans[(i+1)%N]) ||
             (ans[i%N] == 1 && ans[i-1] != ans[(i+1)%N]))) ||
           (s[i%N] == 'x' &&
            ((ans[i%N] == 0 && ans[i-1] != ans[(i+1)%N]) ||
             (ans[i%N] == 1 && ans[i-1] == ans[(i+1)%N]))))) {
        ok = false;
      }
    }
    if(ok) {
      rep(k, N) cout << ani[ans[k]];
      cout << "\n";
      return 0;
    }

  }
  cout << -1 << "\n";
  return 0;
}
