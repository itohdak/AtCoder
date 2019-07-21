#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int> > X(N, vector<int>(D));
  rep(i, N) {
    rep(j, D) {
      cin >> X[i][j];
    }
  }
  int cnt = 0;
  rep(i, N) {
    REP(j, i+1, N) {
      ll tmp = 0LL;
      rep(d, D)
        tmp += pow((X[i][d] - X[j][d]), 2);
      if(tmp == pow(floor(sqrt(tmp)), 2))
        cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

