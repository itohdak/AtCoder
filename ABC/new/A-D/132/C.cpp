#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  rep(i, N) cin >> D[i];
  sort(all(D));
  int ans = D[N/2-1] == D[N/2] ? 0 : D[N/2] - D[N/2-1];
  cout << ans << endl;
  return 0;
}

