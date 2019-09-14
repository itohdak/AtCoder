#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> P(n);
  rep(i, n)
    cin >> P[i];
  int ans = 0;
  REP(i, 1, n-1) {
    if((P[i] - P[i-1]) * (P[i] - P[i+1]) < 0)
      ans++;
  }
  cout << ans << endl;
  return 0;
}

