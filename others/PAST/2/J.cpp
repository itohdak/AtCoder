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
  vector<string> T(1);
  queue<int> Q;
  int tmp = 0;
  for(char c: S) {
    if(c == '(') {
      T.push_back("");
      tmp++;
    } else if(c == ')') {
      T[tmp-1] += T[tmp];
      reverse(all(T[tmp]));
      T[tmp-1] += T[tmp];
      T.pop_back();
      tmp--;
    } else {
      T[tmp] += c;
    }
  }
  cout << T[0] << endl;
  return 0;
}
