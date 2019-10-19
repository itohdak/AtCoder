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
  rep(i, S.size())
    if((i % 2 == 0 && S[i] == 'L') ||
       (i % 2 == 1 && S[i] == 'R')) {
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
  return 0;
}

