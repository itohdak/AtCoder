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
  vector<ld> A(n); rep(i, n) cin >> A[i];
  int mxi = max_element(all(A)) - begin(A);
  ld mx = A[mxi];
  int mni = min_element(all(A)) - begin(A);
  ld mn = A[mni];
  vector<pair<int, int>> ans;
  if(abs(mn) > mx) {
    rrep(i, n) {
      ans.push_back({mni, i});
      ans.push_back({mni, i});
      A[i] += mn*2;
      if(A[i] < mn) {
        mn = A[i];
        mni = i;
      }
    }
  } else {
    rep(i, n) {
      ans.push_back({mxi, i});
      ans.push_back({mxi, i});
      A[i] += mx*2;
      if(A[i] > mx) {
        mx = A[i];
        mxi = i;
      }
    }
  }
  // cout << A << endk;
  cout << ans.size() << endk;
  for(auto a: ans) cout << a.first+1 << ' ' << a.second+1 << endk;
  return 0;
}
