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
  vector<int> L(M), R(M);
  map<int, int> mp;
  rep(i, M) cin >> L[i] >> R[i];
  int begin = 0;
  int end = N;
  rep(i, M) {
    begin = max(L[i], begin);
    end = min(R[i], end);
  }
  cout << max(end-begin+1, 0) << endl;
  return 0;
}

