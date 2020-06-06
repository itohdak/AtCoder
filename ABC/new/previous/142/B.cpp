#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  sort(H.begin(), H.end());
  cout << int(H.end() - lower_bound(H.begin(), H.end(), K)) << endl;
  return 0;
}

