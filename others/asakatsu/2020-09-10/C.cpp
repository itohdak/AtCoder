#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/templates/print.hpp"
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, l;
  cin >> n >> l;
  cin.ignore();
  vector<string> S(l+1);
  rep(i, l+1) getline(cin, S[i]);
  vector<vector<bool>> yoko(l, vector<bool>(n-1));
  rep(i, l) rep(j, n-1) {
    if(S[i][2*j+1] == '-') yoko[i][j] = true;
  }
  int tmp = 0;
  rep(j, n) if(S[l][2*j] == 'o') tmp = j;
  rrep(i, l) {
    if(tmp > 0 && yoko[i][tmp-1]) tmp--;
    else if(tmp < n-1 && yoko[i][tmp]) tmp++;
  }
  cout << tmp+1 << endk;
  return 0;
}
