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
  ll N;
  cin >> N;
  if(N <= 26) {
    cout << char('a'+N-1) << endl;
    return 0;
  }
  ll tmp = 0;
  ll pw = 1;
  int d = 0;
  while(N > tmp) {
    pw *= 26;
    tmp += pw;
    d++;
  }
  string ans(d, ' ');
  ll M = N-tmp/26;
  rep(i, d) {
    ans[i] = 'a' + M % 26;
    M /= 26;
  }
  reverse(all(ans));
  cout << ans << endl;
  return 0;
}
