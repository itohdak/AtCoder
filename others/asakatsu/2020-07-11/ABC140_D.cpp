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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int ans = 0;
  rep(i, n) {
    if(i == 0 && s[i] == 'L') continue;
    if(i == n-1 && s[n-1] == 'R') continue;
    ans += (s[i]=='L' ? s[i]==s[i-1] : s[i]==s[i+1]);
  }
  cout << min(n-1, ans+2*k) << "\n";
  return 0;
}
