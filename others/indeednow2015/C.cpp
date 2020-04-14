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
  vector<ll> S(N), T;
  rep(i, N) {
    cin >> S[i];
    if(S[i] != 0) T.push_back(S[i]);
  }
  sort(all(T), greater<ll>());

  int Q;
  cin >> Q;
  vector<int> K(Q);
  rep(i, Q) {
    cin >> K[i];
    if(K[i] >= T.size()) cout << 0 << endl;
    else cout << T[K[i]]+1 << endl;
  }
  return 0;
}
