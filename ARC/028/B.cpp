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
  int N, K;
  cin >> N >> K;
  vector<int> X(N);
  rep(i, N) cin >> X[i];
  priority_queue<pair<int, int>> Q;
  rep(i, K) Q.push(make_pair(X[i], i+1));
  REP(i, K, N) {
    cout << Q.top().second << endl;
    auto tmp = make_pair(X[i], i+1);
    if(tmp < Q.top()) {
      Q.push(tmp);
      Q.pop();
    }
  }
  cout << Q.top().second << endl;
  return 0;
}
