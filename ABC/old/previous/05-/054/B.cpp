#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];
  rep(i, N-M+1) rep(j, N-M+1) {
    bool ret = true;
    rep(k, M)
      rep(l, M)
      if(A[i+k][j+l] != B[k][l]) ret = false;
    if(ret) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

