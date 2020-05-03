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
  int N, M;
  cin >> N >> M;
  vector<ll> H(N);
  set<int> se;
  rep(i, N) {
    cin >> H[i];
    se.insert(i);
  }
  vector<int> A(M), B(M);
  rep(i, M) {
    cin >> A[i] >> B[i];
    --A[i], --B[i];
    if(H[A[i]] <= H[B[i]]) se.erase(A[i]);
    if(H[A[i]] >= H[B[i]]) se.erase(B[i]);
  }
  cout << se.size() << endl;
  return 0;
}
