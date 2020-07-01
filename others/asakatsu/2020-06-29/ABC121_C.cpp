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
  cin >> N >> M;
  vector<ll> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  vector<int> id(N);
  rep(i, N) id[i] = i;
  sort(all(id), [&](int i, int j) {
      return A[i] < A[j];
    });
  int rem = M;
  int i = 0;
  ll ans = 0;
  while(rem > 0) {
    if(B[id[i]] >= rem) {
      ans += A[id[i]] * rem;
      rem = 0;
    } else {
      ans += A[id[i]] * B[id[i]];
      rem -= B[id[i]];
    }
    i++;
  }
  cout << ans << "\n";
  return 0;
}
