#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S[3];
  cin >> S[0] >> S[1] >> S[2];
  int i[3] = {0, 0, 0};
  int s[3] = {S[0].size(), S[1].size(), S[2].size()};
  int t = 0;
  while(true) {
    if(i[t] >= s[t]) { cout << char('A' + t) << endl; break; }
    else t = S[t][i[t]++] - 'a';
  }
  return 0;
}

