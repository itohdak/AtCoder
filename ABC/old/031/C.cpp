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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll ans = -longinf;
  rep(i, n) {
    ll mx = -longinf;
    ll val = 0;
    rep(j, n) if(i != j) {
      ll tmp = 0;
      ll tmpVal = 0;
      for(int k=min(i,j)+1; k<=max(i,j); k+=2) tmp += A[k];
      for(int k=min(i,j); k<=max(i,j); k+=2) tmpVal += A[k];
      if(tmp > mx) {
        mx = tmp;
        val = tmpVal;
      }
    }
    ans = max(ans, val);
  }
  cout << ans << endk;
  // vector<ll> sumOdd(n+1), sumEven(n+1);
  // rep(i, n) {
  //   if(i%2) {
  //     sumOdd[i+1] = sumOdd[i] + A[i];
  //     sumEven[i+1] = sumEven[i];
  //   } else {
  //     sumEven[i+1] = sumEven[i] + A[i];
  //     sumOdd[i+1] = sumOdd[i];
  //   }
  // }
  // set<pair<ll, int>> stOdd, stEven;
  // ll mx = -longinf;
  // stOdd.insert({-sumOdd[n], n-1});
  // stEven.insert({-sumEven[n], n-1});
  // rrep(i, n-1) {
  //   if(i%2) {
  //     int j = stEven.begin()->second;
  //     cout << i << ' ' << j << ' ' << sumOdd[j+1]-sumOdd[i] << endk;
  //     mx = max(sumOdd[j+1]-sumOdd[i], mx);
  //   } else {
  //     int j = stOdd.begin()->second;
  //     cout << i << ' ' << j << ' ' << sumEven[j+1]-sumEven[i] << endk;
  //     mx = max(sumEven[j+1]-sumEven[i], mx);
  //   }
  //   stOdd.insert({-sumOdd[i+1], i});
  //   stEven.insert({-sumEven[i+1], i});
  // }
  // cout << mx << endk;
  return 0;
}
