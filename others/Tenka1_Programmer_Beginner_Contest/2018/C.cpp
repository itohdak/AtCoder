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
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  if(N%2) {
    int l=0, r=N-1;
    bool flag=1;
    ll sum = A[N-1]-A[N/2];
    rep(i, N-2) {
      sum += A[r]-A[l];
      if(flag) r--;
      else l++;
      flag = 1-flag;
    }
    l=0, r=N-1;
    flag=1;
    ll sum2 = A[N/2]-A[0];
    rep(i, N-2) {
      sum2 += A[r]-A[l];
      if(flag) l++;
      else r--;
      flag = 1-flag;
    }
    cout << max(sum, sum2) << endl;
  } else {
    int l=0, r=N-1;
    bool flag=1;
    ll sum = A[N-1]-A[N/2-1];
    rep(i, N-2) {
      sum += A[r]-A[l];
      if(flag) r--;
      else l++;
      flag = 1-flag;
    }
    cout << sum << endl;
  }
  return 0;
}
