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
  int n, m; cin >> n >> m;
  vector<ll> A(n), B(n), id(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
      return A[i] < A[j];
    });
  // cout << id << "\n";
  int cnt = m;
  ll ans = 0;
  int i = 0;
  while(cnt) {
    if(cnt < B[id[i]]) {
      ans += A[id[i]] * cnt;
      break;
    } else {
      ans += A[id[i]] * B[id[i]];
      cnt -= B[id[i]];
    }
    i++;
  }
  cout << ans << "\n";
  return 0;
}
