#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int digit(int N) {
  return floor(log10(N))+1;
}

int main() {
  int N;
  cin >> N;
  int ans = 0;
  REP(i, 1, N+1)
    if(digit(i) % 2 == 1)
      ans++;
  cout << ans << endl;
  return 0;
}

