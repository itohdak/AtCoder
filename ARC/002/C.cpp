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
  int N;
  string S;
  cin >> N >> S;
  string comm = "ABXY";
  int ans = inf;
  rep(i, 4) rep(j, 4) rep(k, 4) rep(l, 4) {
    string L(2, ' '), R(2, ' ');
    L[0] = comm[i];
    L[1] = comm[j];
    R[0] = comm[k];
    R[1] = comm[l];
    int i = 0;
    int cnt = 0;
    while(i < N) {
      if(i < N-1 && (S.substr(i, 2)==L || S.substr(i, 2)==R)) {
        cnt++;
        i += 2;
      } else {
        cnt++;
        i++;
      }
    }
    ans = min(cnt, ans);
  }
  cout << ans << "\n";
  return 0;
}
