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
  vector<string> S(2);
  vector<int> A(2);
  rep(i, 2) {
    cin >> S[i];
    if(S[i][0] == 'B') A[i] = -(int)(S[i][1]-'1');
    else A[i] = (int)(S[i][0]-'0');
  }
  cout << abs(A[0]-A[1]) << endl;
  return 0;
}
