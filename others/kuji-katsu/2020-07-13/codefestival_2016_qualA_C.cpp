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
  string s; cin >> s;
  ll k; cin >> k;
  int n = s.size();
  rep(i, n) {
    int d = (26-(s[i]-'a')) % 26;
    if(d <= k) {
      k -= d;
      s[i] = 'a';
    }
  }
  k %= 26;
  if(k) s[n-1] = 'a' + ((s[n-1]-'a')+k) % 26;
  cout << s << "\n";
  return 0;
}
