#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> A(2);
  A[0] = vector<pair<int, int>>(1<<N);
  rep(i, 1<<N) {
    cin >> A[0][i].first;
    A[0][i].second = i;
  }
  int tmp = 0;
  int cnt = 1;
  vector<int> ans(1<<N);
  rrep(i, N) {
    A[1-tmp] = vector<pair<int, int>>();
    for(int j=0; j<(1<<(i+1)); j+=2) {
      if(A[tmp][j].first > A[tmp][j+1].first) {
        A[1-tmp].push_back(A[tmp][j]);
        ans[A[tmp][j+1].second] = cnt;
      } else {
        A[1-tmp].push_back(A[tmp][j+1]);
        ans[A[tmp][j].second] = cnt;
      }
    }
    tmp = 1-tmp;
    cnt++;
    // cout << ans << endl;
  }
  for(int a: ans) cout << (a==0 ? N : a) << endl;
  return 0;
}
