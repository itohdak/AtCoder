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
  ll N;
  cin >> N;
  ll depth = 0;
  ll n = N;
  while(n > 0) {
    n >>= 1;
    depth++;
  }
  // cout << depth << endl;
  bool flag = 1;
  ll tmp = 1;
  while(tmp <= N) {
    // cout << tmp << endl;
    tmp *= 2;
    if(flag) {
      if(depth%2) tmp++;
    } else {
      if(depth%2==0) tmp++;
    }
    flag = 1-flag;
  }
  cout << (flag ? "Takahashi" : "Aoki") << endl;
  return 0;
}
