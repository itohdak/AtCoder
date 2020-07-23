#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll L; cin >> n >> L;
  deque<ll> X(n);
  deque<char> D(n);
  rep(i, n) cin >> X[i] >> D[i];
  if(D[n-1] == 'R') {
    X.push_back(L+1);
    D.push_back('L');
  }
  if(D[0] == 'L') {
    X.push_front(0);
    D.push_front('R');
  }
  int l = 0, r = 0;
  int rbegin = 0, rend = 0, lbegin = 0, lend = 0;
  ll ans = 0;
  while(l < X.size()) {
    while(r < X.size() && D[r] == D[l]) r++;
    if(D[l] == 'R') {
      rbegin = l;
      rend = r;
      rep(i, r-l) ans += (X[r-1]-i)-X[r-1-i];
    } else {
      lbegin = l;
      lend = r;
      rep(i, r-l) ans += X[l+i]-(X[l]+i);
      ans += (X[lbegin]-X[rend-1]-1) * max(rend-rbegin, lend-lbegin);
    }
    l = r;
  }
  cout << ans << "\n";
  return 0;
}
