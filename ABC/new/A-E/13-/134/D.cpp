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
  vector<int> A(N+1);
  rep(i, N) cin >> A[i+1];
  vector<int> B(N+1);
  vector<int> ans;
  for(int m=N; m>=1; m--) {
    if(A[m] != B[m]) {
      B[m] = 1 - B[m];
      ans.push_back(m);
      vector<ll> divisor;
      for(int i=1; i<=sqrt(m); i++) {
        if(m % i == 0)
          divisor.push_back(i);
      }
      int n = divisor.size();
      for(int i=n-1; i>=0; i--) {
        if(m != (ll)pow(divisor[i], 2))
          divisor.push_back(m / divisor[i]);
      }
      for(auto d: divisor)
        if(d != m)
          B[d] = 1 - B[d];
    }
  }
  int cnt = ans.size();
  cout << cnt << endl;
  if(cnt != 0) {
    rep(i, cnt)
      cout << ans[cnt-1-i] << ' ';
    cout << endl;
  }
  return 0;
}

