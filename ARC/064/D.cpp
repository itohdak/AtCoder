#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  if((s.size() % 2 == 0) ^ (s[0] == s[s.size()-1]))
    cout << "Second" << endl;
  else
    cout << "First" << endl;
  return 0;
}

