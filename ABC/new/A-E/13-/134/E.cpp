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
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  multiset<ll> S;
  rep(i, N) {
    auto itr = S.upper_bound(A[i]-1);
    if(itr == S.begin()) {
      S.insert(A[i]);
    } else {
      S.erase(--itr);
      S.insert(A[i]);
    }
  }
  cout << S.size() << endl;
  return 0;
}

