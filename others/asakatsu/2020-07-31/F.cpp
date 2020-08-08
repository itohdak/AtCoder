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
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<bool> isLarger(n);
  rep(i, n-1) if(P[i] < P[i+1]) isLarger[i+1] = true;
  vector<int> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + isLarger[i];
  int cnt = 0;
  set<int> st;
  rep(i, k) st.insert(P[i]);
  int ans = 0;
  int sorted = 0;
  if(sum[k]-sum[1] == k-1) sorted++;
  else ans++;
  REP(i, k, n) {
    if(sum[i+1]-sum[i-k+2] == k-1) sorted++;
    else if(*st.begin() != P[i-k] || *st.rbegin() >= P[i]) ans++;
    st.erase(P[i-k]);
    st.insert(P[i]);
  }
  // rep(i, n-k+1) {
  //   vector<int> Q(n);
  //   copy(all(P), Q.begin());
  //   sort(Q.begin()+i, Q.begin()+i+k);
  //   cout << Q << endl;
  // }
  // cout << sorted << "\n";
  cout << ans+(sorted>0) << "\n";
  return 0;
}
