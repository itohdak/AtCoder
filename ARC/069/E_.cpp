#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, int> > A(N);
  rep(i, N) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(all(A), greater<pair<ll, int> >());
  A.push_back(make_pair(0, -1));
  vector<ll> ans(N);
  int mi = A[0].second;
  rep(i, N) {
    mi = min(mi, A[i].second);
    ans[mi] += (i + 1) * (A[i].first - A[i+1].first);
  }
  rep(i, N)
    cout << ans[i] << endl;
  return 0;
}

