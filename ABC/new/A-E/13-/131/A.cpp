#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S;
  cin >> S;
  REP(i, 1, S.size()) {
    if(S[i] == S[i-1]) {
      cout << "Bad" << endl;
      return 0;
    }
  }
  cout << "Good" << endl;
  return 0;
}

