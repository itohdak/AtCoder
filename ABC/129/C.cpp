#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, M;
  cin >> N >> M;
  set<int> A;
  rep(i, M) {
    int a;
    cin >> a;
    A.insert(a);
  }
  vector<ll> B(N+1);
  B[0] = 1;
  rep(i, N+1) {
    if(A.find(i) == A.end()) {
      if(i == 1)
	B[i] = B[i-1] % mod;
      else if(i > 1)
	B[i] = (B[i-1] + B[i-2]) % mod;
    }
  }
  cout << B[N] << endl;
  return 0;
}

