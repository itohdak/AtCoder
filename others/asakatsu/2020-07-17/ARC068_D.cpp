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
  int m = 100005;
  vector<int> cnt(m);
  rep(i, n) {
    cin >> A[i];
    cnt[--A[i]]++;
  }
  int dbl = 0;
  rep(i, m) {
    if(cnt[i] > 1) dbl += cnt[i]-1;
  }
  cout << n-(dbl+1)/2*2 << "\n";
  return 0;
}
