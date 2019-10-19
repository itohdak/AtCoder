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
  ll K;
  int Q;
  cin >> N >> K >> Q;
  vector<int> A(Q);
  vector<int> point(N);
  rep(i, Q) {
    cin >> A[i];
    point[A[i]-1]++;
  }
  rep(i, N) {
    if(K - Q + point[i] > 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

