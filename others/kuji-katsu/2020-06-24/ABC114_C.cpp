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
  ll N;
  cin >> N;
  int d = log10(N)+1;
  int ans = 0;
  int val[] = {7, 5, 3};
  vector<int> cnt(3);
  function<void(int, ll)> dfs = [&](int i, ll tmp) {
    if(tmp <= N && cnt[0] && cnt[1] && cnt[2]) ans++;
    if(i == d) return;
    rep(j, 3) {
      cnt[j]++;
      dfs(i+1, tmp*10+val[j]);
      cnt[j]--;
    }
  };
  dfs(0, 0);
  cout << ans << "\n";
  return 0;
}
