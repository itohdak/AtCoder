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
  int N, K, D;
  cin >> N >> K >> D;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  if(K > (N-1)/D+1) { cout << -1 << endl; return 0; }
  vector<ll> ans(K);
  int tmp = 0;
  set<pair<ll, int>> se;
  rep(i, K) {
    int begin, end;
    begin = (i ? max(N-D*(K-i), tmp) : 0);
    end = N-D*(K-1-i);
    REP(j, begin, end) se.insert(make_pair(A[j], j));
    // cout << se << endl;
    ans[i] = se.begin()->first;
    int id = se.begin()->second;
    // cout << id << endl;
    REP(j, tmp, min(id+D, N)) {
      // cout << make_pair(A[j], j) << endl;
      se.erase(make_pair(A[j], j));
    }
    tmp = id+D;
  }
  for(ll a: ans) cout << a << ' ';
  cout << endl;
  return 0;
}
