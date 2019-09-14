#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int A, B;
  cin >> A >> B;
  if(B == 1)
    cout << 0 << endl;
  else
    cout << 1 + int(ceil(1.0 * max(0, B-A) / (A-1))) << endl;
  return 0;
}

