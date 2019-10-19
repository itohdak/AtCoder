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
  vector<pair<int, int> > P;
  rep(i, N) {
    int p;
    cin >> p;
    P.push_back(make_pair(p, i+1));
  }
  sort(P.begin(), P.end(), greater<pair<int, int> >());
  set<int> S;
  S.insert(0);
  S.insert(N+1);
  ll ans = 0;
  rep(i, N) {
    ll p = P[i].first;
    int idx = P[i].second;
    int r1 = *S.lower_bound(idx+1);
    int r2 = r1 == N+1 ? N+1 : *S.lower_bound(r1+1);
    int l1 = *(--S.upper_bound(idx-1));
    int l2 = l1 == 0 ? 0 : *(--S.upper_bound(l1-1));
    ans += p * ((r2 - r1) * (idx - l1) + (r1 - idx) * (l1 - l2));
    S.insert(idx);
  }
  cout << ans << endl;
  return 0;
}

