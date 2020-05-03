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

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  bool ok = true;
  map<int, int> mpA, mpB;
  vector<ll> cntA(N*M+1), cntB(N*M+1);
  rep(i, N) {
    cin >> A[i];
    if(mpA.count(A[i])) ok = false;
    mpA[A[i]] = i;
    cntA[A[i]]++;
  }
  rep(i, M) {
    cin >> B[i];
    if(mpB.count(B[i])) ok = false;
    mpB[B[i]] = i;
    cntB[B[i]]++;
  }
  rrep(i, N*M) {
    cntA[i] += cntA[i+1];
    cntB[i] += cntB[i+1];
  }
  if(!ok) cout << 0 << endl;
  else {
    ll ans = 1;
    RREP(i, N*M, 1) {
      if(mpA.count(i) && mpB.count(i)) {
        ans *= 1;
      } else if(mpA.count(i)) {
        (ans *= cntB[i]) %= mod;
      } else if(mpB.count(i)) {
        (ans *= cntA[i]) %= mod;
      } else {
        (ans *= max((cntA[i]*cntB[i])-(N*M-i), 0LL)) %= mod;
      }
      // cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
  }
  return 0;
}

