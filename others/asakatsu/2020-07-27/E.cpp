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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string a; cin >> a;
  string b = a;
  reverse(all(b));
  int n = a.size();
  vector<int> diff;
  rep(i, n/2) {
    if(a[i] != b[i]) diff.push_back(i);
  }
  if(diff.size() >= 2) {
    cout << n*25 << "\n";
  } else if(diff.size() == 1) {
    cout << (n-2)*25+2*24 << "\n";
  } else {
    cout << n/2*2*25 << "\n";
  }
  return 0;
}
