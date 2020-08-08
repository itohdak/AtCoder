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
  int n, k; cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(k));
  rep(i, n) rep(j, k) cin >> A[i][j];
  vector<queue<int>> Q(k);
  set<int> passed;
  rep(i, n) {
    rep(j, k) Q[j].push(A[i][j]);
    set<int> st;
    rep(j, k) {
      while(!Q[j].empty() && passed.size()+j*(n-1-i) < k) {
        int a = Q[j].front(); Q[j].pop();
        if(!passed.count(a)) {
          st.insert(a);
          passed.insert(a);
        }
      }
    }
    for(int a: st) cout << a << ' ';
    cout << "\n";
  }
  return 0;
}
