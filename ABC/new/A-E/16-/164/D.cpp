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
  vector<int> cnt(2019);
  ll tmp = 0;
  ll pow = 1;
  ll ans = 0;
  cnt[0] = 1;
  rrep(i, N) {
    (tmp += int(S[i]-'0') * pow) %= 2019;
    // cout << tmp << endl;
    ans += cnt[tmp];
    cnt[tmp]++;
    (pow *= 10) %= 2019;
    // cout << cnt << endl;
  }
  cout << ans << endl;
  return 0;
}
