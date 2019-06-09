#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  vector<vector<int> > A(H, vector<int>(W));
  rep(i, H)
    cin >> S[i];
  rep(i, H) {
    int begin = 0;
    rep(j, W) {
      if(S[i][j] == '#') {
	REP(k, begin, j)
	  A[i][k] += j - begin;
	begin = j+1;
      }
    }
    REP(k, begin, W)
      A[i][k] += W - begin;
  }
  rep(j, W) {
    int begin = 0;
    rep(i, H) {
      if(S[i][j] == '#') {
	REP(k, begin, i)
	  A[k][j] += i - begin;
	begin = i+1;
      }
    }
    REP(k, begin, H)
      A[k][j] += H - begin;
  }
  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      ans = max(A[i][j]-1, ans);
    }
  }
  cout << ans << endl;
  return 0;
}

