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
  vector<pair<int, int>> A(N);
  rep(i, N) cin >> A[i].first >> A[i].second;
  sort(all(A));
  priority_queue<int> Q;
  int tmp = 0;
  ll sum = 0;
  REP(i, 1, N+1) {
    while(tmp < N && A[tmp].first <= i) {
      Q.push(A[tmp].second);
      tmp++;
    }
    sum += Q.top();
    Q.pop();
    cout << sum << endl;
  }
  return 0;
}
