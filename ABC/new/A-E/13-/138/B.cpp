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
  double a = 0;
  rep(i, N) {
    cin >> A[i];
    a += 1 / double(A[i]);
  }
  cout << setprecision(10) << 1 / a << endl;
  return 0;
}

