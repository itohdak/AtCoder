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
  vector<ll> A(N), B(N);
  vector<pair<ll, ll> > C;
  rep(i, N) {
    cin >> A[i] >> B[i];
    C.push_back(make_pair(B[i], A[i]));
  }
  sort(C.begin(), C.end());
  ll S = 0;
  rep(i, N) {
    S += C[i].second;
    if(S > C[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

