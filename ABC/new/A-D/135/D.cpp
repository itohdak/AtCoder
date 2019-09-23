#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int to_digit(char c) {
  return (int)(c-'0') + 0;
}

int main() {
  string S;
  cin >> S;
  int N = S.size();

  vector<int> Rem(N+1);
  Rem[0] = 1;
  rep(i, N)
    Rem[i+1] = (Rem[i] * 10) % 13;

  vector<vector<ll> > A(13, vector<ll>(N+1));
  A[0][0] = 1;
  rep(i, N) {
    if(S[i] == '?') {
      rep(k, 10) {
        int rem = (k * Rem[N-1-i]) % 13;
        rep(j, 13) {
          A[(j+rem)%13][i+1] += A[j][i];
          A[(j+rem)%13][i+1] %= mod;
        }
      }
    } else {
      int rem = (to_digit(S[i]) * Rem[N-1-i]) % 13;
      rep(j, 13) {
        A[(j+rem)%13][i+1] += A[j][i];
        A[(j+rem)%13][i+1] %= mod;
      }
    }
  }
  cout << A[5][N] << endl;
  return 0;
}

