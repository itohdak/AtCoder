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
  vector<int> A(m), B(m);
  vector<vector<int>> G(n);
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    G[A[i]].push_back(B[i]);
  }
  int ans = 0;
  int sub = 0;
  map<ll, int> cnt;
  rep(i, n) {
    if(cnt[i]) {
      ans++;
      cnt.clear();
    }
    for(int ne: G[i]) cnt[ne]++;
  }
  cout << ans << "\n";
  return 0;
}
