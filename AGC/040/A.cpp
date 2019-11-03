#include <bits/stdc++.h>
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
  string S;
  cin >> S;
  int N = S.size();
  S = (S[0] == '>' ? '<' : '>') + S + (S[N-1] == '>' ? '<' : '>');
  vector<ll> A(N+1);
  ll cnt = 0;
  rep(i, N+1) {
    if(S[i] == '>' && S[i+1] == '<') {
      // cout << i << endl;
      A[i] = 0;
      RREP(j, i-1, 0) {
        // cout << "RREP" << j << endl;
        if(A[j+1]+1 > A[j]) {
          cnt += A[j+1] + 1 - A[j];
          A[j] = A[j+1] + 1;
        } else {
          break;
        }
        if(S[j] == '<') break;
      }
      REP(j, i+1, N+1) {
        // cout << "REP" << j << endl;
        cnt += A[j-1] + 1 - A[j];
        A[j] = A[j-1] + 1;
        if(S[j+1] == '>') break;
      }
      // rep(i, N+1) cout << A[i] << ' '; cout << endl;
    }
  }
  // rep(i, N+1) cout << A[i] << ' '; cout << endl;
  cout << cnt << endl;
  return 0;
}

