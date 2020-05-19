#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];
  int dx[] = {1, 1, 1};
  int dy[] = {-1, 0, 1};
  RREP(i, N-2, 0) {
    REP(j, 1, 2*N-2) {
      if(S[i][j] == '#') {
        int cnt = 0;
        rep(k, 3) if(S[i+dx[k]][j+dy[k]] == 'X') cnt++;
        if(cnt) S[i][j] = 'X';
      }
    }
  }
  rep(i, N) cout << S[i] << endl;
  return 0;
}
