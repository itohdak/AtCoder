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
  ll k; cin >> k;
  vector<ll> A(n), B(n);
  map<ll, ll> cnt;
  rep(i, n) {
    cin >> A[i] >> B[i];
    cnt[A[i]] += B[i];
  }
  for(auto ele: cnt) {
    if(k <= ele.second) {
      cout << ele.first << "\n";
      break;
    } else {
      k -= ele.second;
    }
  }
  return 0;
}
