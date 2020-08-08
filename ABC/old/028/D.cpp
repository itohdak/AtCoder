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
  ll n, k; cin >> n >> k;
  ll cnt = 0;
  cnt += (k-1)*(n-k)*6; // l k m
  cnt += (n-k)*3; // k k m
  cnt += (k-1)*3; // l k k
  cnt += 1; // k k k
  cout << fixed << setprecision(15) << (double)cnt/(n*n*n) << endk;
  return 0;
}
