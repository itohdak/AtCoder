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
  string S;
  cin >> S;
  int N = S.size();
  string T[] = {"dream", "dreamer", "erase", "eraser"};
  vector<bool> able(N+1);
  rep(i, N) rep(j, 4) {
    if(S.substr(i, T[j].size()) == T[j]) {
      if(i == 0) able[i+T[j].size()] = true;
      else able[i+T[j].size()] = able[i];
    }
  }
  cout << (able[N] ? "YES" : "NO") << endl;
  return 0;
}

