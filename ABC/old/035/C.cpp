#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> sum(n+1);
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    sum[l]++;
    sum[r]--;
  }
  rep(i, n) sum[i+1] += sum[i];
  string ans(n, ' ');
  rep(i, n) ans[i] = '0'+sum[i]%2;
  cout << ans << endk;
  return 0;
}
