#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  vector<ll> A(N), B(N);
  rep(i, N) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(all(B));
  set<ll> se;
  rep(i, N) if(i&1) se.insert(B[i]);
  int cnt = 0;
  rep(i, N) if(i&1 && !se.count(A[i])) cnt++;
  cout << cnt << endl;
  return 0;
}
