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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> A(M);
  multiset<pair<int, int>> se;
  rep(i, M) {
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    se.emplace(A[i].first, 1);
    se.emplace(A[i].second, -1);
  }
  vector<bool> duplicated(N, true);
  int cnt = 0, prev = 0;
  for(auto s: se) {
    int x = s.first;
    int v = s.second;
    if(x != prev && cnt < 2) {
      REP(i, max(prev, 0), x) duplicated[i] = false;
    }
    cnt += v;
    prev = x;
  }
  // cout << duplicated << endl;
  vector<int> sum(N+1);
  rep(i, N) sum[i+1] = duplicated[i];
  rep(i, N+1) if(i) sum[i] += sum[i-1];
  // cout << sum << endl;

  vector<int> ans;
  rep(i, M) {
    if(sum[A[i].second]-sum[A[i].first] == A[i].second-A[i].first) {
      ans.push_back(i+1);
    }
  }
  cout << ans.size() << endl;
  for(int a: ans) cout << a << endl;
  return 0;
}
