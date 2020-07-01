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
  int N, M;
  ll X, Y;
  cin >> N >> M >> X >> Y;
  vector<ll> A(N), B(M);
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];
  int flag=0;
  ll t = 0;
  int cnt = 0;
  while(true) {
    if(flag==0) {
      auto itr = lower_bound(all(A), t);
      if(itr == A.end()) break;
      t = *itr+X;
      cnt++;
    } else {
      auto itr = lower_bound(all(B), t);
      if(itr == B.end()) break;
      t = *itr+Y;
      cnt++;
    }
    flag = 1-flag;
  }
  cout << cnt/2 << "\n";
  return 0;
}
