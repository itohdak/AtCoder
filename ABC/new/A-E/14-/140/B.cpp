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
  vector<int> A(N), B(N), C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N-1) cin >> C[i];
  int ans = 0;
  rep(i, N) {
    ans += B[A[i]-1];
    if(i != 0 && A[i] == A[i-1]+1)
      ans += C[A[i-1]-1];
  }
  cout << ans << endl;
  return 0;
}

