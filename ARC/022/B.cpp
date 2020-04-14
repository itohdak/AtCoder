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
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int l=0, r=0;
  set<int> se;
  int ans = 0;
  while(r < N) {
    if(!se.count(A[r])) {
      se.insert(A[r]);
    } else {
      ans = max(r-l, ans);
      while(se.count(A[r])) {
	se.erase(A[l]);
	l++;
      }
      se.insert(A[r]);
    }
    r++;
  }
  ans = max(r-l, ans);
  cout << ans << endl;
  return 0;
}
