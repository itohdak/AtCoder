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
  vector<int> V(N);
  rep(i, N) cin >> V[i];
  sort(V.begin(), V.end());
  double ans = 0;
  rep(i, N-1) {
    if(i == 0) ans = (V[i] + V[i+1]) / 2.0;
    else ans = (ans + V[i+1]) / 2.0;
  }
  cout << ans << endl;
  return 0;
}

