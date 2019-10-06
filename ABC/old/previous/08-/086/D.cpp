#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int maxAvailable(vector<ll>& X, vector<ll>& Y, vector<char>& C, int N, int K) {
  vector<vector<int> > B(2*K+1, vector<int>(2*K+1));
  rep(n, 2) {
    rep(i, N) {
      ll x = X[i], y = Y[i];
      char c = C[i];
      if(c == 'W') {
        x = (x + K) % (2 * K);
        y = y % (2 * K);
      } else {
        x = x % (2 * K);
        y = y % (2 * K);
      }
      x = (x + n * K) % (2 * K);
      y = (y + n * K) % (2 * K);
      if(x >= K-1) {
        if(y >= K-1) {
          B[x-K+1][y-K+1]++;
          B[x+1][y+1]++;
          B[x+1][y-K+1]--;
          B[x-K+1][y+1]--;
        } else {
          B[x-K+1][0]++;
          B[x+1][y+1]++;
          B[x+1][0]--;
          B[x-K+1][y+1]--;

          B[x-K+1][y+K+1]++;
          B[x+1][y+K+1]--;
        }
      } else {
        if(y >= K-1) {
          B[0][y-K+1]++;
          B[x+1][y+1]++;
          B[x+1][y-K+1]--;
          B[0][y+1]--;

          B[x+K+1][y-K+1]++;
          B[x+K+1][y+1]--;
        } else {
          B[0][0]++;
          B[x+1][y+1]++;
          B[x+1][0]--;
          B[0][y+1]--;

          B[0][y+K+1]++;
          B[x+1][y+K+1]--;

          B[x+K+1][0]++;
          B[x+K+1][y+1]--;

          B[x+K+1][y+K+1]++;
        }
      }
    }
  }
  rep(i, 2*K) rep(j, 2*K) if(j != 0) B[i][j] += B[i][j-1];
  rep(j, 2*K) rep(i, 2*K) if(i != 0) B[i][j] += B[i-1][j];
  int ans = 0;
  rep(i, 2*K) rep(j, 2*K) ans = max(ans, B[i][j]);
  // rep(i, 2*K) {
  //   rep(j, 2*K) {
  //     cout << B[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  return ans;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> X(N), Y(N);
  vector<char> C(N);
  rep(i, N) cin >> X[i] >> Y[i] >> C[i];
  cout << maxAvailable(X, Y, C, N, K) << endl;
  return 0;
}

