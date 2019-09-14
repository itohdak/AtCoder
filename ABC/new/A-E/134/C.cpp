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
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  vector<int> maxL(N), maxR(N);
  rep(i, N-1)
    maxL[i+1] = max(maxL[i], A[i]);
  maxR[N-1] = A[N-1];
  rep(i, N-1)
    maxR[N-2-i] = max(maxR[N-1-i], A[N-2-i]);
  rep(i, N)
    cout << max(maxL[i], maxR[i+1]) << endl;
  return 0;
}

