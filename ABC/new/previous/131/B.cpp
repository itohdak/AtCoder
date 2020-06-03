#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, L;
  cin >> N >> L;
  vector<pair<int, int> > memo(N);
  rep(i, N)
    memo[i] = make_pair(abs(L+i), L+i);
  sort(memo.begin(), memo.end());
  ll ans = 0;
  REP(i, 1, N)
    ans += memo[i].second;
  cout << ans << endl;
  return 0;
}

