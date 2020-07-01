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
  string s;
  ll K;
  cin >> s >> K;
  int N = s.size();
  int i = 0;
  while(K > 0) {
    int k = ('z'-s[i]+1)%26;
    if(i == N-1) {
      s[i] = 'a'+(int(s[i]-'a')+K)%26;
      K = 0;
    } else if(K >= k) {
      K -= k;
      s[i] = 'a';
    }
    i++;
  }
  cout << s << "\n";
  return 0;
}
