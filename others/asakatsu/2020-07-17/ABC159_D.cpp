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
  int n; cin >> n;
  vector<int> A(n);
  vector<ll> cnt(n);
  rep(i, n) {
    cin >> A[i];
    cnt[--A[i]]++;
  }
  ll sum = 0;
  rep(i, n) sum += cnt[i] * (cnt[i]-1) / 2;
  vector<ll> ans(n);
  rep(i, n) {
    ans[i] = sum - cnt[i] * (cnt[i]-1) / 2 + (cnt[i]-1) * (cnt[i]-2) / 2;
  }
  rep(i, n) cout << ans[A[i]] << "\n";
  return 0;
}
