#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int a;
  string s;
  cin >> a >> s;
  if(a >= 3200)
    cout << s << endl;
  else
    cout << "red" << endl;
  return 0;
}

