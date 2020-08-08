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
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  int ans = 0;
  rep(i, n) {
    int j = n-1;
    while(j>=0 && S[i][j]=='o') j--;
    if(j==-1) continue;
    ans++;
    if(i+1<n) REP(k, j, n) S[i+1][k] = 'o';
  }
  cout << ans << "\n";
  return 0;
}
