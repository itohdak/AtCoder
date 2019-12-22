#include <bits/stdc++.h>
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
vector<vector<pair<int, int> > > A;
int N;
int ans;
vector<int> memo;
bool test(int tmp) {
  for(auto a: A[tmp]) {
    if(a.second && (memo[a.first] == -1 || memo[a.first] == 1)) continue;
    if(!a.second && (memo[a.first] == -1 || memo[a.first] == 0)) continue;
    return false;
  }
  return true;
}
void dfs(int tmp, int par, int value) {
  if(tmp == N) {
    ans = max(ans, value);
    return;
  }
  vector<int> backup(N, -1);
  rep(i, N) backup[i] = memo[i];
  bool ret = test(tmp);
  if(!ret && memo[tmp] == 1) return;
  if(memo[tmp] == 1) {
    for(auto a: A[tmp]) memo[a.first] = a.second;
    dfs(tmp+1, tmp, value+1);
    rep(i, N) memo[i] = backup[i];
  } else if(memo[tmp] != 0 && ret) {
    memo[tmp] = 1;
    for(auto a: A[tmp]) memo[a.first] = a.second;
    dfs(tmp+1, tmp, value+1);
    rep(i, N) memo[i] = backup[i];
    memo[tmp] = 0;
    dfs(tmp+1, tmp, value);
    rep(i, N) memo[i] = backup[i];
  } else {
    memo[tmp] = 0;
    dfs(tmp+1, tmp, value);
    rep(i, N) memo[i] = backup[i];
  }
}
int main() {
  cin >> N;
  A = vector<vector<pair<int, int> > >(N);
  memo = vector<int>(N, -1);
  rep(i, N) {
    int a;
    cin >> a;
    rep(j, a) {
      int x, y;
      cin >> x >> y;
      x--;
      A[i].push_back(make_pair(x, y));
    }
  }
  dfs(0, -1, 0);
  cout << ans << endl;
  return 0;
}
