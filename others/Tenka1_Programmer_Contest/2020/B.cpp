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

bool lower(char c) {
  return ('a' <= c && c <= 'z');
}
bool upper(char c) {
  return ('A' <= c && c <= 'Z');
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();
  bool snake = true, camel = true;
  string prefix, suffix;
  int l = 0, r = N-1;
  while(l<N && S[l]=='_') l++;
  if(l == N) { // "_____..._____"
    cout << S << endl;
    return 0;
  }
  while(r>=0 && S[r]=='_') r--;
  prefix = S.substr(0, l);
  suffix = S.substr(r+1, N-r);
  S = S.substr(l, r-l+1);
  // cout << prefix << ' ' << S << ' ' << suffix << endl;

  N = S.size();
  rep(i, N) {
    if(upper(S[i])) snake = false;
    if(S[i] == '_') camel = false;
    if(i == 0 && !lower(S[i])) snake = camel = false;
    if(S[i] == '_' && i+1<N && !lower(S[i+1])) snake = false;
  }
  if(snake) {
    // cout << "snake" << endl;
    cout << prefix;
    rep(i, N) {
      if(i && S[i] == '_' && i+1<N) {
        cout << (char)toupper(S[i+1]);
        i++;
      }
      else cout << S[i];
    }
    cout << suffix << endl;
  } else if(camel) {
    // cout << "camel" << endl;
    cout << prefix;
    rep(i, N) {
      if(upper(S[i])) cout << '_' << (char)tolower(S[i]);
      else cout << S[i];
    }
    cout << suffix << endl;
  } else {
    cout << prefix << S << suffix << endl;
  }

  return 0;
}
