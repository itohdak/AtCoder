#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

ll to_ll(string s) {
  if(s == "") return 0;
  int n = s.size();
  ll tmp = 1;
  ll ret = 0;
  rep(i, n) {
    ret += int(s[n-1-i] - '0') * tmp;
    tmp *= 10;
  }
  return ret;
}

int main() {
  string S;
  cin >> S;
  int N = S.size();
  ll ans = 0;
  rep(i, 1<<(N-1)) {
    int tmp = 0;
    rep(j, N-1) {
      if(i & 1<<(N-2-j)) {
        ans += to_ll(S.substr(tmp, j+1-tmp));
        tmp = j+1;
      }
    }
    ans += to_ll(S.substr(tmp, N-tmp));
  }
  cout << ans << endl;
  return 0;
}

