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
  if(!(S[0] == S[1] && S[0] == S[2] && S[0] == S[3]) &&
     ((S[0] == S[1] && S[2] == S[3]) ||
      (S[0] == S[2] && S[1] == S[3]) ||
      (S[0] == S[3] && S[1] == S[2]))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

