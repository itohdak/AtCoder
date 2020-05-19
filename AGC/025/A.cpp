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

int digitSum(int n) {
  int ret = 0;
  while(n>0) {
    ret += n%10;
    n/=10;
  }
  return ret;
}
int main() {
  int N;
  cin >> N;
  int mn = inf;
  REP(i, 1, N) {
    mn = min(digitSum(i)+digitSum(N-i), mn);
  }
  cout << mn << endl;
  return 0;
}
