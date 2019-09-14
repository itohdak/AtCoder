#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<int> B(N-1);
  rep(i, N-1)
    cin >> B[i];
  ll ans = 0;
  rep(i, N) {
    if(i == 0)
      ans += B[i];
    else if(i == N-1)
      ans += B[i-1];
    else
      ans += min(B[i], B[i-1]);
  }
  cout << ans << endl;
  return 0;
}

