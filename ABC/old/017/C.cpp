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
  vector<ll> sum(M+1);
  ll sumAll = 0;
  rep(i, N) {
    int l, r, s;
    cin >> l >> r >> s;
    r++;
    sum[l] += s;
    sum[r] -= s;
    sumAll += s;
  }
  rep(i, M+1) sum[i+1] += sum[i];
  // cout << sum << endl;
  ll ans = 0;
  rep(i, M+1) {
    if(i) ans = max(sumAll-sum[i], ans);
  }
  cout << ans << endl;
  return 0;
}
