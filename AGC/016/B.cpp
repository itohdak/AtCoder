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
  map<int, int> mp;
  int mn=N, mx=0;
  rep(i, N) {
    cin >> A[i];
    mp[A[i]]++;
    mn = min(A[i], mn);
    mx = max(A[i], mx);
  }
  switch(mx-mn) {
    case 0:
      if(mp[mn] == mn+1) cout << "Yes" << endl;
      else if(mp[mn] >= mn*2) cout << "Yes" << endl;
      else cout << "No" << endl;
      break;
    case 1:
      if(mp[mn] < mx && 2*(mx-mp[mn]) <= mp[mx]) cout << "Yes" << endl;
      else cout << "No" << endl;
      break;
    default:
      cout << "No" << endl;
  }
  return 0;
}
