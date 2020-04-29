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

int N, M;
vector<int> id;
vector<vector<int>> A;
unordered_set<int> se;
int ans = inf;
void dfs() {
  map<int, int> mp;
  rep(i, N) mp[A[i][id[i]]]++;
  int mx = 0;
  for(auto m: mp) mx = max(m.second, mx);
  ans = min(mx, ans);
  if(se.size() == 1) return;
  vector<int> tmpId(N);
  rep(i, N) tmpId[i] = id[i];
  for(auto m: mp) {
    if(m.second == mx) {
      se.erase(m.first);
      rep(i, N) while(id[i]<M && !se.count(A[i][id[i]])) id[i]++;
      dfs();
      break;
      se.insert(m.first);
      rep(i, N) id[i] = tmpId[i];
    }
  }
}
int main() {
  cin >> N >> M;
  A = vector<vector<int>>(N, vector<int>(M));
  rep(i, N) rep(j, M) cin >> A[i][j];
  id = vector<int>(N);
  rep(i, M) se.insert(i+1);
  dfs();
  cout << ans << endl;
  return 0;
}
