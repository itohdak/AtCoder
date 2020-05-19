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
  int N, A, B;
  string S;
  cin >> N >> A >> B >> S;
  int cntA=0, cntB=0;
  rep(i, N) {
    if(S[i] == 'a') {
      if(cntA+cntB<A+B) {
        cout << "Yes" << endl;
        cntA++;
      } else {
        cout << "No" << endl;
      }
    } else if(S[i] == 'b') {
      if(cntA+cntB<A+B && cntB<B) {
        cout << "Yes" << endl;
        cntB++;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}