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
  vector<ll> A(N), C(M);
  vector<int> B(M);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  vector<pair<ll, int> > CB(M);
  rep(i, M) cin >> CB[i].second >> CB[i].first;
  sort(CB.begin(), CB.end(), greater<pair<ll, int> >());
  vector<ll> D;
  rep(i, M) {
    if(D.size() >= N) break;
    rep(j, CB[i].second)
      D.push_back(CB[i].first);
  }
  ll sum = 0;
  rep(i, N)
    sum += (D.size() > i && A[i] <= D[i]) ? D[i] : A[i];
  cout << sum << endl;
  return 0;
}

